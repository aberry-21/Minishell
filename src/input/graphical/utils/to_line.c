/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:46:45 by aberry            #+#    #+#             */
/*   Updated: 2021/04/24 20:47:15 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		\
	ft_to_line(\
			t_shell *config,\
			int index)
{
	int move;

	move = config->view.draw.yy_global - index;
	if (move < 0)
		ft_down(move * -1);
	if (move > 0)
		ft_up(move);
	config->view.draw.yy_global = index;
}
