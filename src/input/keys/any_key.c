/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:30:08 by telron            #+#    #+#             */
/*   Updated: 2021/01/21 11:00:34 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_input_keys_any_key(t_shell *config, const char chr)
{
	ft_input_cursor_sync(config);
	ft_line_insert_chr(ft_input_cmd_line_get(config)->line,\
		chr, ft_input_command_get(config)->xx_cursor++);
}
