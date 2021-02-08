/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:52:57 by telron            #+#    #+#             */
/*   Updated: 2021/01/25 09:34:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_up(int count)
{
	while (count--)
		write(1, "\033[A", 3);
}

static void		ft_down(int count)
{
	while (count--)
		write(1, "\033[B", 3);
}

void	ft_input_window_clean(t_shell *config)
{
	ft_down(config->draw.yy_real);
	write(1, "\r", 1);
	ft_up(config->draw.lines);
	write(1, "\033[0J\r", 5);
	ft_down(config->draw.lines);
}
