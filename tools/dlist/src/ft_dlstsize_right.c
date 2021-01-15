/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:58:36 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 16:04:04 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

int		ft_dlstsize_right(t_dlist *dlst)
{
	int result;

	result = 0;
	while (dlst)
	{
		dlst = dlst->right;
		result++;
	}
	return (result);
}
