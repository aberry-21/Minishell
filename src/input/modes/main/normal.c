/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 05:05:26 by telron            #+#    #+#             */
/*   Updated: 2021/05/24 21:12:42 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		\
	ft_normal_input_char(\
			t_shell *config,\
			char char_buffer,\
			void *set_keys[][2])
{
	size_t			counter;
	void			**set;
	t_mode_normal	*mode_normal;

	mode_normal = &config->view.mode_normal;
	mode_normal->input_buffer[mode_normal->buffer_length] = char_buffer;
	mode_normal->buffer_length++;
	counter = 0;
	while (*(set = set_keys[counter++]))
	{
		if (!ft_strncmp(mode_normal->input_buffer, set[0], \
												mode_normal->buffer_length))
		{
			if (mode_normal->buffer_length != ft_strlen(set[0]))
				return ;
			((void (*)(t_shell *))set[1])(config);
			break ;
		}
	}
	mode_normal->buffer_length = 0;
	mode_normal->digit_for_normal = 0;
}

void			\
	ft_normal(\
			t_shell *config,\
			char char_buffer)
{
	static void		*set_keys[][2] = {KEY_MODE_TO_INSERT, KEY_BACKSPACE,\
KEY_CURSOR_LEFT_1, KEY_CURSOR_RIGHT_1, KEY_CLIPBOARD_PASTE_DN,\
KEY_CURSOR_UP_1, KEY_CURSOR_DOWN_1, KEY_CURSOR_LEFT_2, KEY_CURSOR_RIGHT_2,\
KEY_CURSOR_UP_2, KEY_CURSOR_DOWN_2, KEY_CURSOR_LEFT_3, KEY_CURSOR_RIGHT_3,\
KEY_CURSOR_UP_3, KEY_CURSOR_DOWN_3, KEY_EXECUTE_LINES, KEY_EXECUTE_COMMAND,\
KEY_CLASSIC_ENTER, KEY_SKIP_WORD_LEFT_1, KEY_SKIP_WORD_RIGHT_1,\
KEY_SKIP_WORD_LEFT_2, KEY_SKIP_WORD_RIGHT_2, KEY_SKIP_WORD_LEFT_3,\
KEY_SKIP_WORD_RIGHT_3, KEY_LINE_HOME_1, KEY_LINE_HOME_2, KEY_LINE_END_1,\
KEY_LINE_END_2, KEY_TO_LINE_OR_HOME, KEY_LINE_ADD_CLIPBOARD,\
KEY_TO_LINE_OR_END, KEY_NEW_LINE_UP, KEY_NEW_LINE_DOWN, KEY_CLIPBOARD_DELETE,\
KEY_LINE_TO_CLIPBOARD, KEY_LINE_DELETE, KEY_COMMAND_LAST, KEY_COMMAND_NEXT,\
KEY_EXIT_IF_LINE_EMPTY, KEY_COMMAND_NEW, KEY_TO_COMMAND_OR_HOME,\
KEY_TO_COMMAND_DELETE, KEY_CLIPBOARD_PASTE_UP, KEY_VIEW_CLIBPORD,\
KEY_VIEW_MAIN, {0, 0}};

	ft_input_view_clean(&config->view.draw);
	if (ft_isdigit(char_buffer))
	{
		config->view.mode_normal.digit_for_normal *= 10;
		config->view.mode_normal.digit_for_normal += char_buffer - '0';
	}
	else
		ft_normal_input_char(config, char_buffer, set_keys);
	ft_input_view_render(config);
}
