/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 01:16:10 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 16:08:29 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_cursor_up(t_shell *config)
{
	t_command	*command;
	size_t		count_line;

	count_line = config->view.mode_normal.digit_for_normal;
	if (!count_line)
		count_line = 1;
	command = ft_input_command_get(config);
	while (command->cmd_line->transport.left && count_line--)
		command->cmd_line = (t_cmd_line *)command->cmd_line->transport.left->content;
}
