/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_elem_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:47:17 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 15:57:08 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict_elem	*ft_dict_elem_init(const char *key, void *content)
{
	t_dict_elem	*result;

	result = (t_dict_elem *)malloc(sizeof(t_dict_elem));
	if (!result)
		return (0);
	result->key = key;
	result->content = content;
	result->next = 0;
	return (result);
}
