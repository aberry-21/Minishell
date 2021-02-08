/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 01:17:24 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 07:19:44 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_cursor_down(t_shell *config)
{
	t_command	*command;
	size_t		count_line;

	count_line = config->input.digit_for_normal;
	if (!count_line)
		count_line = 1;
	command = ft_input_command_get(config);
	if (!command->dlist_cmd_lines->right && count_line == 1)
		ft_input_cmd_line_new(ft_input_command_get(config));
	while (command->dlist_cmd_lines->right && count_line--)
		command->dlist_cmd_lines = command->dlist_cmd_lines->right;
}
