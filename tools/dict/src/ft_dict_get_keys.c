/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_get_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:51:16 by telron            #+#    #+#             */
/*   Updated: 2020/12/07 07:51:25 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char				**ft_dict_get_keys(t_dict *dict)
{
	char		**keys;
	size_t		counter;
	size_t		counter_keys;
	t_dict_elem	*buf;

	if (!(keys = (char **)ft_calloc(dict->count_elem + 1, sizeof(char *))))
		return ((char **)0);
	counter = 0;
	counter_keys = 0;
	while (counter < dict->max_elem)
	{
		if (dict->list[counter])
		{
			buf = dict->list[counter];
			while (buf)
			{
				keys[counter_keys++] = (char *)buf->key;
				buf = buf->next;
			}
		}
		counter++;
	}
	keys[counter_keys] = 0;
	return (keys);
}
