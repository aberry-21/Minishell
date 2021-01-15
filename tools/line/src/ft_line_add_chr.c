/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_add_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:29:08 by telron            #+#    #+#             */
/*   Updated: 2021/01/15 06:27:06 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line		*ft_line_add_chr(t_line *line, char chr)
{
	size_t	add_size;

	if (line->allocated <= line->length + 1)
	{
		add_size = line->allocated >= 16 ? line->allocated : 16;
		if (!ft_line_mem_up(line, add_size))
			return ((t_line *)0);
	}
	line->string[line->length++] = chr;
	line->string[line->length] = 0;
	return (line);
}
