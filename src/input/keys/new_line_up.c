/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 06:17:16 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 06:25:06 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_new_line_up(t_shell *config)
{
	t_command	*command;

	command = ft_input_command_get(config);
	if (ft_input_cmd_line_new_up(ft_input_command_get(config)))
		command->dlist_cmd_lines = command->dlist_cmd_lines->left;
	ft_input_keys_mode_to_insert(config);
}
