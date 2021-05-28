/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 04:02:47 by telron            #+#    #+#             */
/*   Updated: 2021/03/25 22:22:59 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist	*ft_dlstget(\
				t_dlist *dlist,\
				void *value,\
				int (*ft_cmp)(void *, void *))
{
	t_dlist	*begin;

	begin = ft_dlstleft(dlist);
	while (begin)
	{
		if (ft_cmp(begin->content, value))
			return (begin);
		begin = begin->right;
	}
	return (0);
}
