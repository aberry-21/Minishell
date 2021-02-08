/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:33:48 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 08:10:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_command_end(t_shell *config)
{
	t_command	*command;
	t_dlist		*dlist;

	if (config->input.digit_for_normal)
		ft_input_keys_command_home(config);
	else
	{
		command = ft_input_command_get(config);
		dlist = command->dlist_cmd_lines;
		command->dlist_cmd_lines = ft_dlstright(dlist);
		ft_input_keys_line_home(config);
	}
}
