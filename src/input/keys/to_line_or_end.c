/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_line_or_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:33:48 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 16:05:23 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_to_line_or_end(t_shell *config)
{
	t_command	*command;
	t_dlist		*dlist;

	if (config->view.mode_normal.digit_for_normal)
		ft_input_keys_to_line_or_home(config);
	else
	{
		command = ft_input_command_get(config);
		dlist = ft_dlstright(&ft_input_cmd_line_get(config)->transport);
		command->cmd_line = dlist->content;
		ft_input_keys_line_home(config);
	}
}
