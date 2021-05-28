/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipboard_paste_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:14:12 by aberry            #+#    #+#             */
/*   Updated: 2021/04/24 21:20:39 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @function ft_input_keys_clipboard_paste_up
** Вставляет строку из буфера выше на одну строчку
** @рaram Основная структура минишелла
** @author Aaron Berry
** @version 1.0
*/

void		ft_input_keys_clipboard_paste_up(t_shell *config)
{
	t_command	*destination_command;
	t_command	*clipboard;

	destination_command = ft_input_command_get(config);
	clipboard = &config->view.mode_normal.clipboard;
	if (clipboard->cmd_line)
	{
		clipboard->cmd_line = \
						ft_dlstleft(&clipboard->cmd_line->transport)->content;
		if (clipboard->cmd_line)
			ft_input_command_com2com_copy_up(destination_command, \
																clipboard, -1);
	}
}
