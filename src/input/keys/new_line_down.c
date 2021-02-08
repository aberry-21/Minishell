/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 06:17:12 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 06:25:29 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_new_line_down(t_shell *config)
{
	t_command	*command;

	command = ft_input_command_get(config);
	if (ft_input_cmd_line_new(ft_input_command_get(config)))
		command->dlist_cmd_lines = command->dlist_cmd_lines->right;
	ft_input_keys_mode_to_insert(config);
}
