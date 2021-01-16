/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_executable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:19:14 by aberry            #+#    #+#             */
/*   Updated: 2021/01/16 22:13:16 by aberry           ###   ########.fr       */
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

//удалить потом
static void		ft_print_str_split(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
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

static	int		ft_check_path(char **str, char *line_command)
{
	struct stat		filestat;
	int				i;
	int				num;

	i = 0;
	num = -1;
	while (str[i])
	{
		if (!stat(str[i], &filestat))
			num = i;
		i++;
	}
	if (num > -1 && !(filestat.st_mode & S_IXUSR))// пользователь не имеет право выполнения (или группа?)
	{
		printf("minishell>: %s: Permission denied\n", line_command);// временное решение
		num = -1;
	}
	return (num);
}

static char			*ft_find_command(char *line_command, char *env[])
{
	int				i;
	int				index;
	char			**str;
	char			**tmp;
	char			*line;

	i = -1;
	line = NULL;
	while (env[++i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
		{
			str = ft_split(env[i], '=');
			tmp = str;
			str = ft_split(str[1], ':');
			ft_delete_strings(tmp);
			break ;
		}
	}
	ft_strjoin_command(str, line_command);
	index = ft_check_path(str, line_command);
	if (index != -1)
		line = ft_strdup(str[index]);
	ft_delete_strings(str);
	return (line);
}

void	handle_sigint(int sig)
{
	printf("Caught signal %d\n", sig);
	exit(0);
}

void	handle_sigint_r(int sig)//del
{
}

int		ft_launch_executable(char *line_command, char *argv[], char *env[])
{
	char	*str;
	pid_t	pid;

	signal(SIGINT, handle_sigint_r);// del
	signal(SIGQUIT, handle_sigint_r);// del
	str = ft_find_command(line_command, env);
	if (!str)
	{
		printf("Command not found: %s\n", line_command);
		return (-1);
	}
	else
		printf("Command found: %s\n", str);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGQUIT, handle_sigint);
		signal(SIGINT, handle_sigint);
		execve(str, argv, env);
	}
	wait(NULL);
	free(str);
	return (0);
}
