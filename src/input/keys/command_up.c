/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:49:27 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 16:15:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_command_up(t_shell *config)
{
	size_t		count_command;
	t_view		*view;

	view = &config->view;
	count_command = view->mode_normal.digit_for_normal;
	if (!count_command)
		count_command = 1;
	while (view->command->transport.left && count_command--)
	{
		view->command = (t_command *)view->command->transport.left->content;
		view->index_command -= 1;
	}
}
