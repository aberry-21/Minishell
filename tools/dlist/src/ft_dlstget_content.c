/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstget_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 04:03:41 by telron            #+#    #+#             */
/*   Updated: 2021/03/19 04:17:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	*ft_dlstget_content(\
				t_dlist *dlist,\
				void *value,\
				int (*ft_cmp)(void *, void *))
{
	t_dlist *element;

	element = ft_dlstget(dlist, value, ft_cmp);
	return (element ? element->content : 0);
}
