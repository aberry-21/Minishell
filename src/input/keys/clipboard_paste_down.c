/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipboard_paste_down.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:55:23 by telron            #+#    #+#             */
/*   Updated: 2021/04/24 21:19:39 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_clipboard_paste_down(t_shell *config)
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
			ft_input_command_com2com_copy(destination_command, clipboard, -1);
	}
}
