/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:11:46 by telron            #+#    #+#             */
/*   Updated: 2021/02/07 03:53:29 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_line	*ft_build_lines(t_shell *config, t_command *command,\
								size_t count_lines, char from_the_first_line)
{
	size_t		counter;
	t_dlist		*dlist;
	t_cmd_line	*insert_cmd_line;
	t_line		*line;
	t_line		*ptr;

	counter = 0;
	ptr = ~0;
	dlist = from_the_first_line ?\
			ft_dlstleft(command->dlist_cmd_lines) : command->dlist_cmd_lines;
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

static void		ft_run(t_shell *config, t_parse_element *element)
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
	if (!(line = ft_build_lines(config, command, count_lines, from_the_first_line)))
		return ((config->exit_code = 12));
	element = ft_parse_build(config, line);
	// ft_line_del(line);        ?????
	if (element)
	{
		ft_run(config, element);
		ft_parse_element_destructor(element);
	}
	return (config->exit_code);
}

// int				ft_parse_run_cmd_line(t_shell *config, t_cmd_line *cmd_line)
// {
// 	t_line			*line;
// 	t_parse_element	*element;
// 	t_stream		stream;

// 	line = ft_line_create_line(cmd_line->line);
// 	if (line)
// 	{
// 		element = ft_parse_build(line);
// 		stream.descriptors.std_in = 0;
// 		stream.descriptors.std_out = 1;
// 		stream.descriptors.std_err = 2;
// 		ft_parse_element_run(config, &stream, element);
// 		return (stream.exit_code);
// 	}
// 	return (1);
// }

// t_parse_element	*ft_parse_run_command(t_shell *config, t_command *command)
// {
// 	t_line			*line;
// 	t_dlist			*dlist;
// 	t_line			*insert_line;
// 	t_stream		stream;
// 	t_parse_element	*element;

// 	line = ft_line_new(16);
// 	dlist = ft_dlstleft(command->dlist_cmd_lines);
// 	while (dlist && line)
// 	{
// 		insert_line = ((t_cmd_line *)dlist->content)->line;
// 		// if (insert_line->length > 0)
// 		// {
// 		ft_line_add_line(line, ((t_cmd_line *)dlist->content)->line);
// 		if (dlist->right)
// 			ft_line_add_chr(line, '\n');
// 		// }
// 		dlist = dlist->right;
// 	}
// 	if (!line)
// 		return ((t_parse_element *)0);
// 	element = ft_parse_build(line);
// 	stream.descriptors.std_in = 0;
// 	stream.descriptors.std_out = 1;
// 	stream.descriptors.std_err = 2;
// 	ft_parse_element_run(config, &stream, element);
// 	return (stream.exit_code);
// }
