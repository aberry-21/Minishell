/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 05:09:24 by telron            #+#    #+#             */
/*   Updated: 2021/04/24 21:21:52 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void\
	ft_input_keys_command_down(\
			t_shell *config)
{
	size_t		count_command;

	count_command = config->view.mode_normal.digit_for_normal;
	if (!count_command)
		count_command = 1;
	while (config->view.command->transport.right && count_command--)
	{
		config->view.command = \
				(t_command *)config->view.command->transport.right->content;
		config->view.index_command += 1;
	}
}
