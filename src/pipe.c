/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:27:26 by aberry            #+#    #+#             */
/*   Updated: 2021/01/25 21:27:26 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_delete_strings(char **strings)
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

void		ft_dup_streams(t_shell *config)
{
	config->streams->std_in = dup(0);
	config->streams->std_out = dup(1);
	config->streams->std_err = dup(2);
}
void	ft_change_streams(t_shell *config, char *argv[], int fd, int pipefd[])
{
	close(pipefd[!fd]);
	dup2(pipefd[fd], fd);
	ft_launch_executable(argv[0], argv, config);
	close(pipefd[fd]);
}
int		ft_pipe(t_shell *config, char *argv[])
{
	int		pipefd[2];
	pid_t	cpid;
	char	buf;
	char	**argv_first;

	pipe(pipefd);
	cpid = fork();
	argv_first = argv;
	//pipefd[1] = запись 1
	//pipefd[0] = чтение 0
	while (ft_strcmp(*argv, "|") && *argv)
		argv++;
	*argv = 0;
	argv++;
	if (cpid == 0)
	{ 
		// ft_putendl_fd("sun", 1);
		ft_change_streams(config, argv, 0, pipefd);
		dup2(config->streams->std_in, 0);
		exit(0);
	}
	else
	{
		// ft_putendl_fd("GPARENT", 1);
		ft_change_streams(config, argv_first, 1, pipefd);
		dup2(config->streams->std_out, 1);
		wait(0);
	}
	return (0);
}