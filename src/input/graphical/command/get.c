/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:37:42 by telron            #+#    #+#             */
/*   Updated: 2021/01/20 08:39:12 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*ft_input_command_get(t_shell *config)
{
	if (config->dlist_command)
		return ((t_command *)config->dlist_command->content);
	return ((t_command *)0);
}
