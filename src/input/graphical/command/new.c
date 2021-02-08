/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 07:16:43 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 17:16:00 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*ft_input_command_create(t_shell *config)
{
	t_command *command;

	command = (t_command *)ft_calloc(sizeof(t_command), 1);
	// if (command)
	// {
	// 	command->config = config;
	// }
	return (command);
}

t_command	*ft_input_command_new(t_shell *config)
{
	t_command	*new_command;
	t_dlist		*new_dlist;

	if (!(new_command = ft_input_command_create(config)))
		return ((t_command	*)0);
	if (!(new_dlist = ft_dlstadd_right_content(&(config->dlist_command), new_command)))
	{
		//ft_inp_del_command(command);
		return ((t_command	*)0);
	}
	// new_command->up = new_dlist;
	if (!ft_input_cmd_line_new(new_command))
	{
		//ft_inp_del_command(new_command);
		//удалить new_dlist
		return ((t_command	*)0);
	}
	config->count_command += 1;
	// if (!ft_input_cmd_line_new(new_command))
	// {
	// 	//ft_inp_del_command(new_command);
	// 	//удалить new_dlist
	// 	return ((t_command	*)0);
	// }
	return (new_command);
}
