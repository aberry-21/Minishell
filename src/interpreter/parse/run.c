/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:11:46 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 12:05:00 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_line	*ft_build_lines(t_command *command,\
								size_t count_lines, char from_the_first_line)
{
	size_t		counter;
	t_dlist		*dlist;
	t_cmd_line	*insert_cmd_line;
	t_line		*line;
	t_line		*ptr;

	counter = 0;
	ptr = (t_line *)-1;
	dlist = from_the_first_line ?\
			ft_dlstleft(&command->cmd_line->transport) : &command->cmd_line->transport;
	line = ft_line_create_str("");
	while (line && dlist && counter++ < count_lines &&\
		(insert_cmd_line = (t_cmd_line *)dlist->content))
	{
		if (!(ptr = ft_line_add_line(line, insert_cmd_line->line)) ||
			((dlist->right) && (!(ptr = ft_line_add_chr(line, '\n')))))
			break ;
		dlist = dlist->right;
	}
	if (line && (!insert_cmd_line || !ptr))
	{
		ft_line_del(line);
		line = 0;
	}
	return (line);
}

void			ft_run(t_shell *config, t_parse_element *element)
{
	t_stream	stream;

	stream.exit_code = 0;
	stream.descriptors.std_in = 0;
	stream.descriptors.std_out = 1;
	stream.descriptors.std_err = 2;
	ft_parse_element_run(config, &stream, element);
	config->exit_code = stream.exit_code;
}

int				ft_run_cmd_lines(t_shell *config, size_t count_lines,\
								char from_the_first_line)
{
	t_line			*line;
	t_parse_element	*element;
	t_command		*command;

	command = ft_input_command_get(config);
	if (!command)
		return ((config->exit_code = 66));
	if (!(line = ft_build_lines(command, count_lines, from_the_first_line)))
		return ((config->exit_code = 12));
	element = ft_parse_build(config, line);
	ft_line_del(line);
	if (element)
	{
		ft_run(config, element);
		ft_parse_element_destructor(element);
	}
	return (config->exit_code);
}
