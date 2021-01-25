/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_insert_chr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 08:14:07 by telron            #+#    #+#             */
/*   Updated: 2021/01/17 03:17:51 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

static t_line	*ft_lite(t_line *line, char chr, size_t index)
{
	ft_memmove(line->string + 1 + index,\
				line->string + index,\
				line->length - index);
	line->string[index] = chr;
	line->string[++line->length] = '\0';
	return (line);
}

static t_line	*ft_hard(t_line *line, char chr, size_t index)
{
	ft_line_mem_up(line, line->allocated < 16 ? 16 : line->allocated);
	return (ft_lite(line, chr, index));
}

t_line			*ft_line_insert_chr(t_line *line, char chr, size_t index)
{
	if (line->allocated > line->length + 1)
		return (ft_lite(line, chr, index));
	return (ft_hard(line, chr, index));
}
