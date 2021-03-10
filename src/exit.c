/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:23:18 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 15:25:12 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_shell *config)
{
	if (config->view.mode != MODE_SCRIPT)
		ft_reset_mode();
	// sleep(10);
	exit((unsigned char)config->exit_code);
}
