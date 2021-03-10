/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:50:17 by telron            #+#    #+#             */
/*   Updated: 2021/02/28 15:14:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	*ft_dict_get(t_dict *dict, const char *key)
{
	size_t		index;
	t_dict_elem	*elem;

	if (!dict || !key)
		return (0);
	index = ft_dict_hash_function(key, dict->max_elem);
	elem = ft_dict_get_elem_by_key(((dict->hash_table)[index]), key);
	return (elem ? elem->list.content : 0);
}
