/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:14:41 by telron            #+#    #+#             */
/*   Updated: 2020/11/07 01:37:37 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t first, size_t second)
{
	return (first > second ? second : first);
}

int				ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t min_len;

	min_len = ft_min(ft_strlen(str1), ft_strlen(str2));
	return (ft_memcmp(str1, str2, ft_min(size, min_len + 1)));
}
