/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_main_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:38:11 by telron            #+#    #+#             */
/*   Updated: 2021/05/02 13:38:26 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_view_main_command(t_shell *config)
{
	config->view.canvas = CANVAS_MAIN;
}
