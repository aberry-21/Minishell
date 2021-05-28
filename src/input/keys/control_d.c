/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:26:27 by telron            #+#    #+#             */
/*   Updated: 2021/05/28 14:04:16 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_control_d(t_shell *config)
{
	t_command	*command;

	command = ft_input_command_get(config);
	if (!ft_command_length(command))
		ft_exit(config);
}
