/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:04:34 by telron            #+#    #+#             */
/*   Updated: 2020/12/08 01:44:02 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

int		ft_dlstsize(t_dlist *dlst)
{
	return (ft_dlstsize_left(dlst->left) +\
			(dlst != 0) +\
			ft_dlstsize_right(dlst->right));
}
