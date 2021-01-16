/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_add_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 07:57:54 by telron            #+#    #+#             */
/*   Updated: 2021/01/15 22:08:44 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line		*ft_line_add_str(t_line *line, const char *part_2)
{
	size_t	len;
	char	*part_1;

	len = ft_strlen(part_2);
	part_1 = line->string;
	if (len + line->length >= line->allocated)
	{
		if (!ft_line_mem_up_to(line, len + line->length))
			return ((t_line *)0);
		ft_strcpy(line->string, part_1);
	}
	ft_strcpy(line->string + len, part_2);
	return (line);
}
