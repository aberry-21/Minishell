/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_mem_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:29:23 by telron            #+#    #+#             */
/*   Updated: 2021/01/15 14:34:36 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line		*ft_line_mem_up(t_line *line, size_t size)
{
	char	*for_free;
	char	*alloc_memmory;

	if (size)
	{
		for_free = line->string;
		alloc_memmory = (char *)malloc(line->allocated + size);
		if (!alloc_memmory)
			return ((t_line *)0);
		free(for_free);
		line->string = alloc_memmory;
		line->allocated = line->allocated + size;
		ft_line_cpy_str(line, for_free);
		free(for_free);
	}
	return (line);
}
