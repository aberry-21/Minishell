/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:40:09 by telron            #+#    #+#             */
/*   Updated: 2021/03/02 10:50:51 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

inline void\
	ft_up(\
			int count)
{
	while (count--)
		write(1, "\033[A", 3);
}

inline void\
	ft_down(\
			int count)
{
	while (count--)
		write(1, "\033[B", 3);
}

inline void\
	ft_right(\
			int count)
{
	while (count--)
		write(1, "\033[C", 3);
}

inline void\
	ft_put_n(\
			int count)
{
	while (count--)
		write(1, "\n", 1);
}
