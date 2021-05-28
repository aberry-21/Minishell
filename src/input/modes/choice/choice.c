/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:49:05 by telron            #+#    #+#             */
/*   Updated: 2021/05/18 15:54:13 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_choice_make(t_shell *config, t_dlist *dlist)
{
	t_command	*command;

	command = &config->view.mode_choice.choice;
	if (command->cmd_line)
	{
		ft_dlstiter_all_right(&command->cmd_line->transport,\
			(void (*)(void*))ft_input_cmd_line_delone);
		command->cmd_line = 0;
	}
	while (dlist)
	{
		ft_input_cmd_line_new(command);
		if (command->cmd_line->transport.right)
			command->cmd_line = \
				(t_cmd_line *)command->cmd_line->transport.right->content;
		ft_line_cpy_line(\
			command->cmd_line->line,\
			(t_line *)dlist->content);
		dlist = dlist->right;
	}
	return (0);
}

static void		ft_init_mode_choice(t_shell *config, \
									char char_buffer)
{
	t_mode_choice *mode_choice;

	ft_input_view_clean(&config->view.draw);
	mode_choice = &config->view.mode_choice;
	mode_choice->input_buffer[mode_choice->buffer_length] = char_buffer;
	mode_choice->buffer_length++;
}

static int		ft_reload_view_render(t_shell *config)
{
	config->view.mode_choice.buffer_length = 0;
	ft_input_view_render(config);
	return (0);
}

int				ft_choice(t_shell *config, char char_buffer)
{
	static void		*set_keys[][2] = {KEY_CURSOR_UP_3, KEY_CURSOR_DOWN_3, \
																	{0, 0}};
	size_t			counter;
	void			**set;

	ft_init_mode_choice(config, char_buffer);
	counter = 0;
	if (char_buffer == '\n')
		return (1);
	while (*set_keys[counter])
	{
		set = set_keys[counter++];
		if (!ft_strncmp(config->view.mode_choice.input_buffer, set[0], \
							config->view.mode_choice.buffer_length))
		{
			if (config->view.mode_choice.buffer_length == ft_strlen(set[0]))
			{
				((void (*)(t_shell *))set[1])(config);
				break ;
			}
			ft_input_view_render(config);
			return (0);
		}
	}
	return (ft_reload_view_render(config));
}
