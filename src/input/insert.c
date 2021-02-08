/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:10:34 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 19:04:44 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_insert(t_shell *config, char char_buff)
{
	ft_input_window_clean(config);
	if (char_buff == '\033')
		config->input.mode = MODE_NORMAL;
	else if (char_buff == '\n')
		ft_input_keys_enter_line(config);
	// else if (*buff == '\004') // control-Decho 
	// 	break;
	else if (char_buff == 127)
		ft_input_keys_delete(config);
	else if (char_buff && ft_isascii(char_buff))
		ft_input_keys_any_key(config, char_buff);
	ft_input_window_render(config);
}
