/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:31 by telron            #+#    #+#             */
/*   Updated: 2021/02/19 23:26:06 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_pipe_run(\
				t_shell *config,\
				t_stream *stream,\
				t_parse_pipe *element)
{
	int			fd[2];
	pid_t		childpid;
	int			save_fd_in;

	pipe(fd);
	childpid = fork();
	if (!childpid)
	{
		close(fd[0]);
		stream->descriptors.std_out = fd[1];
		ft_parse_element_run(config, stream, element->left);
		close(fd[1]);
		exit(0);
	}
	close(fd[1]);
	wait(0);
	save_fd_in = stream->descriptors.std_in;
	stream->descriptors.std_in = fd[0];
	ft_parse_element_run(config, stream, element->right);
	stream->descriptors.std_in = save_fd_in;
	close(fd[0]);
}
