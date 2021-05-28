/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:58:18 by telron            #+#    #+#             */
/*   Updated: 2021/05/28 01:09:03 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_command_new(t_shell *config)
{
	size_t	save_digit;

	ft_input_command_new(&config->view);
	save_digit = config->view.mode_normal.digit_for_normal;
	config->view.mode_normal.digit_for_normal = -1;
	ft_input_keys_command_down(config);
	config->view.mode_normal.digit_for_normal = save_digit;
}
