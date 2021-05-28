/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:45:56 by aberry            #+#    #+#             */
/*   Updated: 2021/04/24 20:46:43 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		\
	ft_input_init_draw(\
			t_shell *config)
{
	config->view.draw.lines = (g_winsize.ws_row - 1) / 2;
}
