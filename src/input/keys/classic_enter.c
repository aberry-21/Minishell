/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classic_enter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 07:40:22 by telron            #+#    #+#             */
/*   Updated: 2021/04/24 21:21:16 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_classic_enter(t_shell *config)
{
	t_cmd_line	*cmd_line;
	t_cmd_line	*cmd_line_right;
	t_command	*command;

	ft_input_cursor_sync(config);
	cmd_line = ft_input_cmd_line_get(config);
	command = ft_input_command_get(config);
	ft_input_cmd_line_new(command);
	cmd_line_right = (t_cmd_line *)cmd_line->transport.right->content;
	ft_line_add_str(cmd_line_right->line, cmd_line->line->string\
														+ command->xx_cursor);
	ft_line_cut_index(cmd_line->line, command->xx_cursor);
	command->cmd_line = cmd_line_right;
	command->xx_cursor = 0;
}
