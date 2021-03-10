/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:05:00 by telron            #+#    #+#             */
/*   Updated: 2021/03/02 10:57:21 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void\
	ft_input_command_render(\
			t_shell *config)
{
	t_dlist			*dlist;
	t_dlist			*result;
	size_t			counter;
	size_t			add_counter;
	size_t			index;
	t_output_line	*output_line;
	t_line			*line;
	t_dlist			*new;
	t_command		*command;

	result = 0;
	index = 1;
	command = ft_input_command_get(config);
	config->view.draw.middle = 0;
	dlist = ft_dlstleft(&command->cmd_line->transport);
	while (dlist)
	{
		counter = 0;
		line = ((t_cmd_line *)dlist->content)->line;
		while (counter <= line->length)
		{
			add_counter = g_winsize.ws_col;
			if (!counter)
				add_counter -= command->len_prefix;
			output_line = ft_input_output_line_new(\
								line, index, counter, counter + add_counter);
			new = ft_dlstnew(output_line);
			if (&command->cmd_line->transport == dlist)
				output_line->is_cursor_line = 1;
			if (&command->cmd_line->transport == dlist &&\
				((counter <= command->xx_cursor && command->xx_cursor < counter + add_counter) ||\
				(line->length < command->xx_cursor)))
				config->view.draw.middle = new;
			ft_dlstadd_right(&result, new);
			counter += add_counter;
		}
		dlist = dlist->right;
		index++;
	}
}
