/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_line_or_home.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:33:50 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 16:07:49 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_to_line_or_home(t_shell *config)
{
	t_command	*command;

	command = ft_input_command_get(config);
	command->cmd_line = (t_cmd_line *)ft_dlstleft(&command->cmd_line->transport)->content;
	if (config->view.mode_normal.digit_for_normal > 1)
	{
		config->view.mode_normal.digit_for_normal--;
		ft_input_keys_cursor_down(config);
	}
	ft_input_keys_line_home(config);
}
