/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_line_or_home.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:33:50 by telron            #+#    #+#             */
/*   Updated: 2021/04/24 21:29:01 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_to_line_or_home(t_shell *config)
{
	t_command	*command;

	command = ft_input_command_get(config);
	command->cmd_line = \
			(t_cmd_line *)ft_dlstleft(&command->cmd_line->transport)->content;
	if (config->view.mode_normal.digit_for_normal > 1)
	{
		config->view.mode_normal.digit_for_normal--;
		ft_input_keys_cursor_down(config);
	}
	ft_input_keys_line_home(config);
}
