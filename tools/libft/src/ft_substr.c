/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:14:03 by telron            #+#    #+#             */
/*   Updated: 2020/11/05 02:25:54 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int first, int second)
{
	return (first > second ? second : first);
}

char		*ft_substr(char const *str, unsigned int start, size_t size)
{
	char	*result;
	size_t	len;

	if (!str)
		return ((char *)0);
	len = ft_strlen(str);
	if (len <= (size_t)start)
		return (ft_strdup(""));
	len = ft_min(len - (size_t)start, size);
	result = (char *)malloc(len + 1);
	if (!result)
		return ((char *)0);
	ft_strlcpy(result, str + start, len + 1);
	return (result);
}
