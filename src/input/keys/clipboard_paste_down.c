/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipboard_paste_down.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:55:23 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 19:49:57 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_clipboard_paste_down(t_shell *config)
{
	size_t		count_line;
	t_command	*destination_command;

	destination_command = ft_input_command_get(config);
	count_line = config->input.digit_for_normal;
	if (!count_line)
		count_line++;
	destination_command->count_cmd_lines += ft_input_command_com2com_copy(\
		config, &destination_command->dlist_cmd_lines,\
		ft_dlstleft(config->input.clipboard.dlist_cmd_lines), -1);
}
