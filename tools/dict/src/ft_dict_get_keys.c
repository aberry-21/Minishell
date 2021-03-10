/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_get_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:51:16 by telron            #+#    #+#             */
/*   Updated: 2021/02/28 15:10:18 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static void			ft_zeroing_static(size_t *counter, t_dict_elem **elem)
{
	*counter = 0;
	*elem = 0;
}

const char			*ft_dict_iter_keys(t_dict *dict)
{
	static size_t		counter_in_hash_table = 0;
	static t_dict_elem	*elem_now;
	const char			*key;

	if (!dict)
	{
		ft_zeroing_static(&counter_in_hash_table, &elem_now);
		return (0);
	}
	while (counter_in_hash_table < dict->max_elem)
	{
		if (dict->hash_table[counter_in_hash_table])
		{
			if (!elem_now)
				elem_now = dict->hash_table[counter_in_hash_table];
			key = elem_now->key;
			if (!(elem_now = (t_dict_elem *)elem_now->list.next))
				counter_in_hash_table++;
			return (key);
		}
		counter_in_hash_table++;
	}
	ft_zeroing_static(&counter_in_hash_table, &elem_now);
	return (0);
}

void				*ft_dict_iter_value(t_dict *dict)
{
	static size_t		counter_in_hash_table = 0;
	static t_dict_elem	*elem_now;
	void				*value;

	if (!dict)
	{
		ft_zeroing_static(&counter_in_hash_table, &elem_now);
		return (0);
	}
	while (counter_in_hash_table < dict->max_elem)
	{
		if (dict->hash_table[counter_in_hash_table])
		{
			if (!elem_now)
				elem_now = dict->hash_table[counter_in_hash_table];
			value = elem_now->list.content;
			if (!(elem_now = (t_dict_elem *)elem_now->list.next))
				counter_in_hash_table++;
			return (value);
		}
		counter_in_hash_table++;
	}
	ft_zeroing_static(&counter_in_hash_table, &elem_now);
	return (0);
}

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
		if (dict->hash_table[counter])
		{
			buf = dict->hash_table[counter];
			while (buf)
			{
				keys[counter_keys++] = (char *)buf->key;
				buf = (t_dict_elem *)buf->list.next;
			}
		}
		counter++;
	}
	keys[counter_keys] = 0;
	return (keys);
}
