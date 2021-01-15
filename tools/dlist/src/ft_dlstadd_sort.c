/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 03:49:08 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 16:03:07 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstadd_sort(t_dlist **dlst, t_dlist *new, int (*f)(void *, void *))
{
	int	direction;

	if (!dlst || !new || !f)
		return ;
	if (!*dlst)
	{
		*dlst = new;
		return ;
	}
	direction = 0;
	while (*dlst)
	{
		if (0 < f((*dlst)->content, new->content) && 0 <= direction)
		{
			direction = 1;
			*dlst = (*dlst)->left;
		}
		else if (0 >= direction)
		{
			direction = -1;
			*dlst = (*dlst)->right;
		}
		else
		{
			if (0 < direction)
				ft_dlstinsert(*dlst, new, (*dlst)->right);
			else
				ft_dlstinsert((*dlst)->left, new, *dlst);
			break ;
		}
	}
}
