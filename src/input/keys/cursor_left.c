/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 00:54:55 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 16:18:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_cursor_left(t_shell *config)
{
	size_t		count_symbol;
	t_command	*command;

	command = ft_input_command_get(config);
	count_symbol = config->view.mode_normal.digit_for_normal;
	if (!count_symbol)
		count_symbol = 1;
	ft_input_cursor_sync(config);
	if (command->xx_cursor < count_symbol)
		command->xx_cursor = 0;
	else
		command->xx_cursor -= count_symbol;
}
