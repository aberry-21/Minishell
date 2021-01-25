/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:50:17 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 15:56:07 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	*ft_dict_get(t_dict *dict, const char *key)
{
	size_t		index;
	t_dict_elem	*elem;

	index = ft_dict_hash_function(key, dict->max_elem);
	elem = ft_dict_get_elem_by_key(((dict->list)[index]), key);
	return (elem ? elem->content : 0);
}
