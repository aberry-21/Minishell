/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_setting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 03:16:59 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 17:22:23 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_SETTING_H
# define KEY_SETTING_H

# include "minishell_structs.h"

void		ft_input_keys_any_key(t_shell *config, char chr);

void		ft_input_keys_mode_to_insert(t_shell *config);
void		ft_input_keys_mode_to_normal(t_shell *config);

void		ft_input_keys_delete(t_shell *config);
void		ft_input_keys_cursor_left(t_shell *config);
void		ft_input_keys_cursor_left_to_insert(t_shell *config);
void		ft_input_keys_cursor_right(t_shell *config);
void		ft_input_keys_cursor_right_to_insert(t_shell *config);
void		ft_input_keys_cursor_up(t_shell *config);
void		ft_input_keys_cursor_up_to_insert(t_shell *config);
void		ft_input_keys_cursor_down(t_shell *config);
void		ft_input_keys_cursor_down_to_insert(t_shell *config);
void		ft_input_keys_enter(t_shell *config);
void		ft_input_keys_enter_line(t_shell *config);
void		ft_input_keys_command_up(t_shell *config);
void		ft_input_keys_command_down(t_shell *config);
void		ft_input_keys_classic_enter(t_shell *config);
void		ft_input_keys_skip_word_right(t_shell *config);
void		ft_input_keys_skip_word_left(t_shell *config);
void		ft_input_keys_line_home(t_shell *config);
void		ft_input_keys_line_end(t_shell *config);
void		ft_input_keys_to_line_or_home(t_shell *config);
void		ft_input_keys_to_line_or_end(t_shell *config);
void		ft_input_keys_new_line_up(t_shell *config);
void		ft_input_keys_new_line_down(t_shell *config);
void		ft_input_keys_line_add_clipboard(t_shell *config);//+
void		ft_input_keys_clipboard_paste_down(t_shell *config);
void		ft_input_keys_clipboard_clear(t_shell *config);
void		ft_input_keys_line_to_clipboard(t_shell *config);
void		ft_input_keys_line_delete(t_shell *config);
void		ft_input_keys_tab_prompt(t_shell *config);
void		ft_input_keys_command_new(t_shell *config);
void		ft_input_keys_to_command_or_home(t_shell *config);
void		ft_input_keys_command_delete(t_shell *config);

void		ft_input_keys_control_d(t_shell *config);

# define MODE_INSERT			0
# define MODE_NORMAL			1
# define MODE_SCRIPT			2

# define MODE_DEFAULT			MODE_INSERT

# define KEY_MODE_TO_INSERT		{"i", ft_input_keys_mode_to_insert}
# define KEY_BACKSPACE			{"\177", ft_input_keys_delete}
# define KEY_CURSOR_LEFT_1		{"h", ft_input_keys_cursor_left}
# define KEY_CURSOR_RIGHT_1		{"l", ft_input_keys_cursor_right}
# define KEY_CURSOR_UP_1		{"k", ft_input_keys_cursor_up}
# define KEY_CURSOR_DOWN_1		{"j", ft_input_keys_cursor_down}
# define KEY_CURSOR_LEFT_2		{"[D", ft_input_keys_cursor_left_to_insert}
# define KEY_CURSOR_RIGHT_2		{"[C", ft_input_keys_cursor_right_to_insert}
# define KEY_CURSOR_UP_2		{"[A", ft_input_keys_cursor_up_to_insert}
# define KEY_CURSOR_DOWN_2		{"[B", ft_input_keys_cursor_down_to_insert}
# define KEY_CURSOR_LEFT_3		{"\033[D", ft_input_keys_cursor_left}
# define KEY_CURSOR_RIGHT_3		{"\033[C", ft_input_keys_cursor_right}
# define KEY_CURSOR_UP_3		{"\033[A", ft_input_keys_cursor_up}
# define KEY_CURSOR_DOWN_3		{"\033[B", ft_input_keys_cursor_down}
# define KEY_EXECUTE_LINES		{"\n", ft_input_keys_enter_line}
# define KEY_EXECUTE_COMMAND	{"a\n", ft_input_keys_enter}
# define KEY_CLASSIC_ENTER		{"\\\n", ft_input_keys_classic_enter}
# define KEY_SKIP_WORD_LEFT_1	{"b", ft_input_keys_skip_word_left}
# define KEY_SKIP_WORD_RIGHT_1	{"e", ft_input_keys_skip_word_right}
# define KEY_SKIP_WORD_LEFT_2	{"[1;2D", ft_input_keys_skip_word_left}
# define KEY_SKIP_WORD_RIGHT_2	{"[1;2C", ft_input_keys_skip_word_right}
# define KEY_SKIP_WORD_LEFT_3	{"\033[1;2D", ft_input_keys_skip_word_left}
# define KEY_SKIP_WORD_RIGHT_3	{"\033[1;2C", ft_input_keys_skip_word_right}
# define KEY_LINE_HOME_1		{"\033[H", ft_input_keys_line_home}
# define KEY_LINE_END_1			{"\033[F", ft_input_keys_line_end}
# define KEY_LINE_HOME_2		{"[H", ft_input_keys_line_home}
# define KEY_LINE_END_2			{"[F", ft_input_keys_line_end}
# define KEY_TO_LINE_OR_HOME	{"gg", ft_input_keys_to_line_or_home}
# define KEY_TO_LINE_OR_END		{"G", ft_input_keys_to_line_or_end}
# define KEY_NEW_LINE_UP		{"O", ft_input_keys_new_line_up}
# define KEY_NEW_LINE_DOWN		{"o", ft_input_keys_new_line_down}
# define KEY_LINE_ADD_CLIPBOARD	{"ya", ft_input_keys_line_add_clipboard}
# define KEY_LINE_TO_CLIPBOARD	{"yy", ft_input_keys_line_to_clipboard}
# define KEY_CLIPBOARD_DELETE	{"yd", ft_input_keys_clipboard_clear}
# define KEY_CLIPBOARD_PASTE_DN	{"p", ft_input_keys_clipboard_paste_down}
# define KEY_LINE_DELETE		{"dd", ft_input_keys_line_delete}

# define KEY_COMMAND_LAST		{"z", ft_input_keys_command_up}
# define KEY_COMMAND_NEXT		{"x", ft_input_keys_command_down}
# define KEY_COMMAND_NEW		{"cn", ft_input_keys_command_new}
# define KEY_TO_COMMAND_OR_HOME	{"cc", ft_input_keys_to_command_or_home}
# define KEY_TO_COMMAND_DELETE	{"cd", ft_input_keys_command_delete}




# define KEY_EXIT_IF_LINE_EMPTY	{"\004", ft_input_keys_control_d}

# define SET_KEYS				{KEY_MODE_TO_INSERT, KEY_BACKSPACE,\
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
KEY_TO_COMMAND_DELETE, {0, 0}}

#endif
