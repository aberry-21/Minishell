/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:58:18 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 16:24:46 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_command_new(t_shell *config)
{
	// config->input.digit_for_normal = -1;
	// ft_input_keys_command_down(config);
	ft_input_command_new(&config->view);
	config->view.mode_normal.digit_for_normal = -1;
	ft_input_keys_command_down(config);
}
