/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:53:41 by telron            #+#    #+#             */
/*   Updated: 2021/05/27 17:03:29 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static void		\
	ft_note_normal_input_char(\
			t_shell *config,\
			char char_buffer,\
			void *set_keys[][2])
{
	size_t			counter;
	void			**set;
	t_mode_note		*mode_note;

	mode_note = &config->view.mode_note;
	mode_note->input_buffer[mode_note->buffer_length] = char_buffer;
	mode_note->buffer_length++;
	counter = 0;
	while (*(set = set_keys[counter++]))
	{
		if (!ft_strncmp(mode_note->input_buffer, set[0], \
							mode_note->buffer_length))
		{
			if (mode_note->buffer_length != ft_strlen(set[0]))
				return ;
			((void (*)(t_shell *))set[1])(config);
			break ;
		}
	}
	mode_note->buffer_length = 0;
	mode_note->digit_for_normal = 0;
}

void			\
	ft_note_normal(\
			t_shell *config,\
			char char_buffer)
{
	static void		*set_keys[][2] = {KEY_MODE_TO_INSERT, KEY_BACKSPACE,\
KEY_CURSOR_LEFT_1, KEY_CURSOR_RIGHT_1, KEY_CLIPBOARD_PASTE_DN,\
KEY_CURSOR_UP_1, KEY_CURSOR_DOWN_1, KEY_CURSOR_LEFT_2, KEY_CURSOR_RIGHT_2,\
KEY_CURSOR_UP_2, KEY_CURSOR_DOWN_2, KEY_CURSOR_LEFT_3, KEY_CURSOR_RIGHT_3,\
KEY_CURSOR_UP_3, KEY_CURSOR_DOWN_3,\
{"\n", ft_input_keys_classic_enter}, KEY_SKIP_WORD_LEFT_1, KEY_SKIP_WORD_RIGHT_1,\
KEY_SKIP_WORD_LEFT_2, KEY_SKIP_WORD_RIGHT_2, KEY_SKIP_WORD_LEFT_3,\
KEY_SKIP_WORD_RIGHT_3, KEY_LINE_HOME_1, KEY_LINE_HOME_2, KEY_LINE_END_1,\
KEY_LINE_END_2, KEY_TO_LINE_OR_HOME, KEY_LINE_ADD_CLIPBOARD,\
KEY_TO_LINE_OR_END, KEY_NEW_LINE_UP, KEY_NEW_LINE_DOWN, KEY_CLIPBOARD_DELETE,\
KEY_LINE_TO_CLIPBOARD, KEY_LINE_DELETE,\
KEY_EXIT_IF_LINE_EMPTY,\
KEY_CLIPBOARD_PASTE_UP,\
KEY_VIEW_MAIN, {0, 0}};

	ft_input_view_clean(&config->view.draw);
	if (ft_isdigit(char_buffer))
	{
		config->view.mode_note.digit_for_normal *= 10;
		config->view.mode_note.digit_for_normal += char_buffer - '0';
	}
	else
		ft_note_normal_input_char(config, char_buffer, set_keys);
	ft_input_view_render(config);
}
