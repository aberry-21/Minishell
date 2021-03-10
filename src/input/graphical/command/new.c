/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 07:16:43 by telron            #+#    #+#             */
/*   Updated: 2021/03/02 10:56:47 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command\
	*ft_input_command_create(\
			void)
{
	t_command *command;

	command = (t_command *)ft_calloc(1, sizeof(t_command));
	if (command)
		command->transport.content = command;
	return (command);
}

t_command\
	*ft_input_command_new(\
			t_view *view)
{
	t_command	*new_command;

	if (!(new_command = ft_input_command_create()))
		return ((t_command	*)0);
	if (view->command)
		ft_dlstrelation(
			ft_dlstright(&view->command->transport),
			&new_command->transport);
	else
		view->command = new_command;
	if (!ft_input_cmd_line_new(new_command))
	{
		ft_input_command_delone(new_command);
		return ((t_command	*)0);
	}
	view->count_command += 1;
	return (new_command);
}
