/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 05:09:24 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 06:41:13 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_command_down(t_shell *config)
{
	if (config->dlist_command->right)
	{
		config->dlist_command = config->dlist_command->right;
		config->index_command += 1;
	}
}
