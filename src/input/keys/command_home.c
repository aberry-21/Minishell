/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_home.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:33:50 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 07:56:45 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_command_home(t_shell *config)
{
	t_command	*command;
	t_dlist		*dlist;

	command = ft_input_command_get(config);
	dlist = command->dlist_cmd_lines;
	command->dlist_cmd_lines = ft_dlstleft(dlist);
	if (config->input.digit_for_normal > 1)
	{
		config->input.digit_for_normal--;
		ft_input_keys_cursor_down(config);
	}
	ft_input_keys_line_home(config);
}
