/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiteri_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:41:20 by telron            #+#    #+#             */
/*   Updated: 2021/01/28 21:12:31 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstiteri_right(t_dlist *dlst, void (*f)(size_t, void *))
{
	size_t	counter;

	counter = 0;
	while (dlst)
	{
		f(counter, dlst->content);
		dlst = dlst->right;
		counter++;
	}
}
