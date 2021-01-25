/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:44:26 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 15:56:56 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int					ft_dict_add(t_dict **dict, const char *key, void *content)
{
	size_t		index;
	t_dict_elem *now;
	t_dict_elem *elem;

	if ((double)((*dict)->count_elem) > (double)((*dict)->max_elem) * 0.7)
		if (ft_dict_double(dict) == -1)
			return (-1);
	index = ft_dict_hash_function(key, (*dict)->max_elem);
	if (!(now = (*dict)->list[index]))
	{
		if (!(elem = ft_dict_elem_init(key, content)))
			return (-1);
		(*dict)->list[index] = elem;
	}
	else if ((elem = ft_dict_get_elem_by_key(now, key)))
	{
		elem->content = content;
		return (0);
	}
	else if (!(elem = ft_dict_elem_init(key, content)))
		return (-1);
	else
		ft_dict_elem_add_back(&now, elem);
	(*dict)->count_elem++;
	return (0);
}
