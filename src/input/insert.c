/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:10:34 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 17:17:12 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_insert(t_shell *config, char char_buff)
{
	ft_input_view_clean(&config->view.draw);
	if (char_buff == '\033')
		config->view.mode = MODE_NORMAL;
	else if (char_buff == '\n')
		ft_input_keys_enter_line(config);
	else if (char_buff == '\t')
		ft_input_keys_tab_prompt(config);
	else if (char_buff == '\004') // control-Decho 
		ft_exit(config);
	else if (char_buff == 127)
		ft_input_keys_delete(config);
	else if (char_buff && ft_isascii(char_buff))
		ft_input_keys_any_key(config, char_buff);
	ft_input_view_render(config);
}
