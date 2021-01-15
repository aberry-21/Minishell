/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:57:03 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 16:04:00 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

int		ft_dlstsize_left(t_dlist *dlst)
{
	int result;

	result = 0;
	while (dlst)
	{
		dlst = dlst->left;
		result++;
	}
	return (result);
}
