/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:39:32 by telron            #+#    #+#             */
/*   Updated: 2020/12/08 00:40:03 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstclear_left(t_dlist **dlst, void (*del)(void*))
{
	t_dlist *buf;

	while (dlst && *dlst)
	{
		if ((*dlst)->right)
			(*dlst)->right = 0;
		buf = (*dlst)->left;
		ft_dlstdelone(*dlst, del);
		*dlst = buf;
	}
	*dlst = 0;
}
