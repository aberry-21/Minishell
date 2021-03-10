/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipboard_paste_down.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:55:23 by telron            #+#    #+#             */
/*   Updated: 2021/03/02 00:23:04 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_clipboard_paste_down(t_shell *config)
{
	size_t		count_line;
	t_command	*destination_command;
	t_command	*clipboard;

	destination_command = ft_input_command_get(config);
	clipboard = &config->view.mode_normal.clipboard;
	count_line = config->view.mode_normal.digit_for_normal;
	if (!count_line)
		count_line = 1;
	if (clipboard->cmd_line)
	{
		clipboard->cmd_line = ft_dlstleft(&clipboard->cmd_line->transport)->content;
		if (clipboard->cmd_line)
			destination_command->count_cmd_lines += ft_input_command_com2com_copy(\
				destination_command,\
				clipboard, -1);
	}
}
