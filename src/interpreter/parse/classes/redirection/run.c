/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:31 by telron            #+#    #+#             */
/*   Updated: 2021/02/19 23:29:12 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_error_handler(\
						t_shell *config,\
						t_stream *stream,\
						t_line *name_file,\
						int type)
{
	if (type == 1)
	{
		ft_error_print(config, "ft_parse_redirection_run", name_file->string, "Permission denied");
		stream->exit_code = 1;
	}
	ft_line_del(name_file);
	return ;
}

static t_line	*ft_get_file_name(\
						t_shell *config,\
						t_dlist *file_name_dlist)
{
	t_line			*line;
	t_parse_element	*element;
	char			*variable_value;

	line = ft_line_create_str("");
	while (file_name_dlist)
	{
		element = (t_parse_element *)file_name_dlist->content;
		if (element->type == STRING_CODE)
			ft_line_add_line(line, element->content.string.line);
		else if (element->type == IMMUTABLE_CODE)
			ft_line_add_line(line, element->content.immutable.line);
		else if (element->type == VARIABLE_CODE)
		{
			if ((variable_value = ft_env_var_get_by_user(config, element->content.variable.line->string)))
				ft_line_add_str(line, variable_value);
		}
		file_name_dlist = file_name_dlist->right;
	}
	return (line);
}

void			ft_parse_redirection_run(\
						t_shell *config,\
						t_stream *stream,\
						t_parse_redirection *redirection)
{
	t_line	*name_file;
	int		save_fd;

	name_file = ft_get_file_name(config, redirection->name_file);
	if (1 == redirection->type || 2 == redirection->type || 4 == redirection->type)
	{
		save_fd = redirection->type == 4 ? stream->descriptors.std_in : stream->descriptors.std_out;
		if (redirection->type == 1)
		{
			if ((stream->descriptors.std_out = open(name_file->string, O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1)
				return (ft_error_handler(config, stream, name_file, 1));
		}
		else if (redirection->type == 2)
		{
			if ((stream->descriptors.std_out = open(name_file->string, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
				return (ft_error_handler(config, stream, name_file, 1));
		}
		else if ((stream->descriptors.std_in = open(name_file->string, O_RDONLY)) == -1)
				return (ft_error_handler(config, stream, name_file, 1));
		ft_parse_element_run(config, stream, redirection->element);
		close(redirection->type == 4 ? stream->descriptors.std_in : stream->descriptors.std_out);
		if (redirection->type == 4)
			stream->descriptors.std_in = save_fd;
		else
			stream->descriptors.std_out = save_fd;
	}
	else
		ft_parse_element_run(config, stream, redirection->element);
	ft_line_del(name_file);
}
