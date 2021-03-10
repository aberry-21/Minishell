/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 00:00:21 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 16:36:47 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_command_delete(t_shell *config)
{
	t_dlist		*dlist;
	size_t		count_command;
	t_view		*view;

	view = &config->view;
	dlist = &view->command->transport;
	count_command = config->view.mode_normal.digit_for_normal;
	if (!count_command)
		count_command++;
	while (dlist && count_command--)
	{
		if (dlist->right)
			view->command = dlist->right->content;
		else
		{
			view->command = dlist->left->content;
			view->index_command--;
			count_command = 0;
		}
		ft_dlstrelation(dlist->left, dlist->right);
		ft_dlstdelone(dlist, (void (*)(void*))ft_input_command_delone);
		view->count_command--;
		dlist = &view->command->transport;
	}
	if (!view->command)
	{
		ft_input_command_new(view);
		view->index_command++;
	}
}
