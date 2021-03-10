/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:44:26 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 05:41:36 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int					ft_dict_add(t_dict **dict, const char *key, void *value)
{
	size_t		index;
	t_dict_elem *now;
	t_dict_elem *elem;

	if ((double)((*dict)->count_elem) > (double)((*dict)->max_elem) * 0.7)
		if (ft_dict_double(dict) == -1)
			return (-1);
	index = ft_dict_hash_function(key, (*dict)->max_elem);
	if (!(now = (*dict)->hash_table[index]))
	{
		if (!(elem = ft_dict_elem_init(key, value)))
			return (-1);
		(*dict)->hash_table[index] = elem;
	}
	else if ((elem = ft_dict_get_elem_by_key(now, key)))
	{
		elem->list.content = value;
		return (0);
	}
	else if (!(elem = ft_dict_elem_init(key, value)))
		return (-1);
	else
		ft_lstadd_back((t_list **)&now, (t_list *)elem);
	(*dict)->count_elem++;
	return (0);
}
