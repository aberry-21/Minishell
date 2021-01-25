/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_elem_add_back.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:54:52 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 15:55:09 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static t_dict_elem	*ft_dict_elem_last(t_dict_elem *elem)
{
	while (elem->next)
		elem = elem->next;
	return (elem);
}

void				ft_dict_elem_add_back(t_dict_elem **elem, t_dict_elem *new)
{
	if (*elem)
		ft_dict_elem_last(*elem)->next = new;
	*elem = new;
}
