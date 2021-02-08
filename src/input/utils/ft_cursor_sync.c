/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_sync.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:55:21 by telron            #+#    #+#             */
/*   Updated: 2021/01/21 11:00:11 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_input_cursor_sync(t_shell *config)
{
	t_command	*command;
	t_cmd_line	*cmd_line;

	command = ft_input_command_get(config);
	cmd_line = ft_input_cmd_line_get(config);
	if (cmd_line->line->length < command->xx_cursor)
		command->xx_cursor = cmd_line->line->length;
}
