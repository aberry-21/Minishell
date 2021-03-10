/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_command_or_home.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:24:53 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 16:28:16 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_to_command_or_home(t_shell *config)
{
	t_view	*view;

	view = &config->view;
	view->command = ft_dlstleft(&view->command->transport)->content;
	view->index_command = 1;
	while (view->command->transport.right && view->mode_normal.digit_for_normal > 1)
	{
		view->mode_normal.digit_for_normal--;
		view->command = view->command->transport.right->content;
		view->index_command += 1;
	}
}
