/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_executable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:19:14 by aberry            #+#    #+#             */
/*   Updated: 2021/02/07 19:23:08 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>
#include <sys/types.h>


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
	//"ls"
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
	// ft_print_str_split(str);
	index = ft_check_path(str, line_command);
	if (index != -1)
		line = ft_strdup(str[index]);
	ft_delete_strings(str);
	return (line);
}

void handle_sigint(int sig)
{
	printf("Caught signal %d\n", sig);
	exit(0);
}

void handle_sigint_r(int sig)//del
{
}

// int		ft_launch_executable(char *line_command, char *argv[], char *env[])
// {
// 	char	*str;
// 	pid_t	pid;

// 	// signal(SIGINT, handle_sigint_r);// del
// 	// signal(SIGQUIT, handle_sigint_r);// del
// 	str = ft_find_command(line_command, env);
// 	if (!str)
// 	{
// 		// printf("Command not found: %s\n", line_command);
// 		return (-1);
// 	}
// 	// else
// 		// printf("Command found: %s\n", str);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		signal(SIGQUIT, handle_sigint);
// 		signal(SIGINT, handle_sigint);
// 		execve(str, argv, env);
// 	}
// 	wait(NULL);
// 	free(str);
// 	return (0);
// }

static void	ft_save_fd(t_descriptors *fd_saved)
{
	fd_saved->std_in = dup(0);
	fd_saved->std_out = dup(1);
	fd_saved->std_err = dup(2);
}

static void	ft_reload_fd(t_descriptors *fd_saved)
{
	dup2(fd_saved->std_in, 0);
	dup2(fd_saved->std_out, 1);
	dup2(fd_saved->std_err, 2);
}

int	ft_launch_executable(t_shell *config, t_executable *executable)
{
	pid_t		cpid;
	pid_t		origin_in;
	t_stream	fd_saved;
	int			status;
	char		*path_bin;

	path_bin = ft_find_command(executable->argums[0], config->env_origin);
	if (!path_bin)
	{
		// printf("Command not found: %s\n", line_command);
		return (-1);
	}
	ft_save_fd(&fd_saved);
	dup2(executable->descriptors.std_in, 0);
	dup2(executable->descriptors.std_out, 1);
	dup2(executable->descriptors.std_err, 2);
	cpid = fork();
	if (!cpid)
		execve(path_bin, executable->argums, config->env_origin);
	waitpid(cpid, &status, 0);
	ft_reload_fd(&fd_saved);
	return (status);
}

