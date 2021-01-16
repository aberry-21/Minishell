/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_insert_chr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 08:14:07 by telron            #+#    #+#             */
/*   Updated: 2021/01/16 08:26:01 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line		*ft_line_insert_chr(t_line *line, char chr, size_t index)
{
	size_t	counter;
	char	*string;

	string = line->string;
	ft_line_mem_up_to(line, line->length + 1);
	line->string[line->length + 1] = 0;
	counter = line->length;
	while (1)
	{
		line->string[counter + 1] = string[counter];
		if (index == counter)
			break ;
		counter--;
	}
	line->string[index] = chr;
	line->length++;
	return (line);
}
