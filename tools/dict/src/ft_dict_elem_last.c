/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_elem_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:55:48 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 15:56:41 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict_elem	*ft_dict_elem_last(t_dict_elem *elem)
{
	while (elem->next)
		elem = elem->next;
	return (elem);
}
