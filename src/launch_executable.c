/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_executable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olebedev <olebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:19:14 by aberry            #+#    #+#             */
/*   Updated: 2021/01/22 22:57:03 by olebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>
#include <sys/types.h>

// сделать ее не статической в сплите 
static void		ft_delete_strings(char **strings)
{
	size_t counter;

	counter = 0;
	while (strings && strings[counter])
	{
		free(strings[counter]);
		counter++;
	}
	free(strings);
}

static void		ft_strjoin_command(char **str, char *line_command)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	line = ft_strjoin("/", line_command);
	while (str[i])
	{
		tmp = str[i];
		str[i] = ft_strjoin(str[i], line);
		free(tmp);
		i++;
	}
	free(line);
}

static	char		*ft_check_path(char **str, char *line_command)
{
	struct stat		filestat;
	int				i;
	char			*exe;

	i = 0;
	exe = NULL;
	while (str && str[i])
	{
		if (!stat(str[i], &filestat))
			exe = ft_strdup(str[i]);
		i++;
	}
	if (!exe)
		printf("minishell>: %s: No such file or directory\n", line_command);// временное решение
	else if (!(filestat.st_mode & S_IXUSR))// пользователь не имеет право выполнения (или группа?)
	{
		free(exe);
		exe = NULL;
		printf("minishell>: %s: Permission denied\n", line_command);// временное решение
	}
	return (exe);
}

static char			**ft_find_command(char *line_command, t_shell *config)
{
	char		*value_path;
	char			**paths;

	value_path = (char *)ft_dict_get(config->env, "PATH");
	if (!value_path)
		return (NULL);
	paths = ft_split(value_path, ':');
	ft_strjoin_command(paths, line_command);
	return (paths);
}

static char			*ft_choose_path(char *line_command, t_shell *config)
{
	char			*exe;
	char			**line;

	if (line_command[0] == '.' || line_command[0] == '/' )
		line = ft_split(line_command, ' ');
	else
		line = ft_find_command(line_command, config);
	exe = ft_check_path(line, line_command);
	ft_delete_strings(line);
	return (exe);
}

void	handle_sigint(int sig)
{
	printf("Caught signal %d\n", sig);
	exit(0);
}

void	handle_sigint_r(int sig)//del
{
}

int		ft_launch_executable(char *line_command, char *argv[], t_shell *config)
{
	char	*exe;
	pid_t	pid;
	int		return_value;

	signal(SIGINT, handle_sigint_r);// del
	signal(SIGQUIT, handle_sigint_r);// del
	return_value = 1;
	exe = ft_choose_path(line_command, config);
	if (exe)
	{
		return_value = 0;
		pid = fork();
		if (pid == 0)
		{
			signal(SIGQUIT, handle_sigint);
			signal(SIGINT, handle_sigint);
			execve(exe, argv, ft_env_dict_to_string(config));
		}
		wait(NULL);
	}
	free(exe);
	return (return_value);
}
