/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:31 by telron            #+#    #+#             */
/*   Updated: 2021/02/06 03:37:34 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_line	*ft_get_file_name(t_shell *config, t_dlist *file_name_dlist)
{
	t_line			*line;
	t_parse_element	*element;

	line = ft_line_create_str("");
	while (file_name_dlist)
	{
		element = (t_parse_element *)file_name_dlist->content;
		if (element->type == STRING_CODE)
			ft_line_add_line(line, element->content.string.line);
		else if (element->type == IMMUTABLE_CODE)
			ft_line_add_line(line, element->content.immutable.line);
		else if (element->type == VARIABLE_CODE)
			ft_line_add_str(line, ft_env_get(config, element->content.variable.line->string));
		file_name_dlist = file_name_dlist->right;
	}
	return (line);
}

void			ft_parse_redirection_run(t_shell *config, t_stream *stream, t_parse_redirection *redirection)
{
	t_line	*name_file;
	int		save_fd;

	name_file = ft_get_file_name(config, redirection->name_file);
	dprintf(FD_LOG, "\n|%s|%d|<-type\n", name_file->string, redirection->type);
	if (redirection->type == 2)
	{
		save_fd = stream->descriptors.std_out;
		stream->descriptors.std_out = open(name_file->string, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ft_parse_element_run(config, stream, redirection->element);
		close(stream->descriptors.std_out);
		stream->descriptors.std_out = save_fd;
		ft_line_del(name_file);
	}
	else if (redirection->type == 1)
	{
		save_fd = stream->descriptors.std_out;
		stream->descriptors.std_out = open(name_file->string, O_WRONLY | O_CREAT | O_APPEND, 0644);
		ft_parse_element_run(config, stream, redirection->element);
		close(stream->descriptors.std_out);
		stream->descriptors.std_out = save_fd;
		ft_line_del(name_file);
	}
	else if (redirection->type == 4)
	{
		save_fd = stream->descriptors.std_in;
		stream->descriptors.std_in = open(name_file->string, O_RDONLY);
		ft_parse_element_run(config, stream, redirection->element);
		close(stream->descriptors.std_in);
		stream->descriptors.std_in = save_fd;
		ft_line_del(name_file);
	}
	else
		ft_parse_element_run(config, stream, redirection->element);
}
