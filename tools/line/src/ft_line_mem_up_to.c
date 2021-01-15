/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_mem_up_to.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 04:36:31 by telron            #+#    #+#             */
/*   Updated: 2021/01/15 05:11:00 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line		*ft_line_mem_up_to(t_line *line, size_t length)
{
	size_t	new_size_allocated;
	char	*buf;

	new_size_allocated = line->allocated;
	while (new_size_allocated < length + 1)
	{
		if (!new_size_allocated)
			new_size_allocated = 16;
		else
			new_size_allocated *= 2;
	}
	if (line->allocated != new_size_allocated)
	{
		if (!(buf = (char *)malloc(new_size_allocated)))
			return ((t_line *)0);
		free(line->string);
		line->string = buf;
		line->allocated = new_size_allocated;
	}
	return (line);
}
