/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:49:27 by telron            #+#    #+#             */
/*   Updated: 2021/01/23 19:13:57 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_command_up(t_shell *config)
{
	if (config->dlist_command->left)
	{
		config->dlist_command = config->dlist_command->left;
		config->index_command -= 1;
	}
}
