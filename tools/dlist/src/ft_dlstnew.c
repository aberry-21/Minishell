/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:55:53 by telron            #+#    #+#             */
/*   Updated: 2020/12/07 23:01:38 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist		*ft_dlstnew(void *content)
{
	t_dlist	*result;

	result = (t_dlist *)malloc(sizeof(t_dlist));
	if (!result)
		return (0);
	result->content = content;
	result->left = 0;
	result->right = 0;
	return (result);
}
