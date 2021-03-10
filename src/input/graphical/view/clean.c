/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:52:57 by telron            #+#    #+#             */
/*   Updated: 2021/03/02 10:39:50 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_input_view_clean(t_draw *draw)
{
	ft_down(draw->yy_real);
	write(1, "\r", 1);
	ft_up(draw->lines);
	write(1, "\033[0J\r", 5);
	ft_down(draw->lines);
}
