/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 01:16:10 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 07:13:39 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_cursor_up(t_shell *config)
{
	t_command	*command;
	size_t		count_line;

	count_line = config->input.digit_for_normal;
	if (!count_line)
		count_line = 1;
	command = ft_input_command_get(config);
	while (command->dlist_cmd_lines->left && count_line--)
		command->dlist_cmd_lines = command->dlist_cmd_lines->left;
}
