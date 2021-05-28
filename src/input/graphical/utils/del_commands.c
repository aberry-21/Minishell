/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:41:59 by telron            #+#    #+#             */
/*   Updated: 2021/04/24 16:49:16 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_del_commands(t_shell *config)
{
	ft_dlstiter_all_right(&config->view.command->transport,\
		(void (*)(void*))ft_input_command_delone);
}
