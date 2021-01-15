/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_cpy_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:36:15 by telron            #+#    #+#             */
/*   Updated: 2021/01/15 01:51:51 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line		*ft_line_cpy_str(t_line *destination, const char *sourse)
{
	size_t	len;
	size_t	new_size_allocated;
	char	*buf;

	len = ft_strlen(sourse);
	new_size_allocated = destination->allocated;
	while (new_size_allocated < len + 1)
	{
		if (!new_size_allocated)
			new_size_allocated = 16;
		else
			new_size_allocated *= 2;
	}
	if (destination->allocated != new_size_allocated)
	{
		if (!(buf = (char *)malloc(new_size_allocated)))
			return ((t_line *)0);
		free(destination->string);
		destination->string = buf;
		destination->allocated = new_size_allocated;
	}
	destination->length = len;
	destination->string[len] = '\0';
	while (len--)
		destination->string[len] = sourse[len];
	return (destination);
}
