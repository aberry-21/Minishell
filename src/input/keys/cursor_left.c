/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 00:54:55 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 06:44:26 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_cursor_left(t_shell *config)
{
	size_t	count_symbol;

	count_symbol = config->input.digit_for_normal;
	if (!count_symbol)
		count_symbol = 1;
	ft_input_cursor_sync(config);
	if (ft_input_command_get(config)->xx_cursor < count_symbol)
		ft_input_command_get(config)->xx_cursor = 0;
	else
		ft_input_command_get(config)->xx_cursor -= count_symbol;
}
