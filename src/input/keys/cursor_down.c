/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 01:17:24 by telron            #+#    #+#             */
/*   Updated: 2021/05/24 13:32:35 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_cursor_down(t_shell *config)
{
	t_command	*command;
	size_t		count_line;

	command = ft_input_command_get(config);
	count_line = 1;
	if (config->view.mode == MODE_NORMAL)
	{
		if (config->view.mode_normal.digit_for_normal)
			count_line = config->view.mode_normal.digit_for_normal;
	}
	if (!command->cmd_line->transport.right && count_line == 1)
			ft_input_cmd_line_new(command);
	while (command->cmd_line->transport.right && count_line--)
		command->cmd_line = \
				(t_cmd_line *)command->cmd_line->transport.right->content;
}
