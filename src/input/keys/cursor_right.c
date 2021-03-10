/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 01:08:04 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 16:05:34 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_input_keys_cursor_right(t_shell *config)
{
	size_t	count_symbol;
	size_t	now_length;

	count_symbol = config->view.mode_normal.digit_for_normal;
	if (!count_symbol)
		count_symbol = 1;
	ft_input_cursor_sync(config);
	now_length = ft_input_cmd_line_get(config)->line->length;
	if (ft_input_command_get(config)->xx_cursor + count_symbol > now_length)
		ft_input_command_get(config)->xx_cursor = now_length;
	else
		ft_input_command_get(config)->xx_cursor += count_symbol;
}
