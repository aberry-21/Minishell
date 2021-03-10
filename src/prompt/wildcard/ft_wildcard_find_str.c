/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard_find_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:12:41 by aberry            #+#    #+#             */
/*   Updated: 2021/02/28 13:40:08 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_wildcard_check_name(char **parts_pattern, char *name,\
														char *pattern, size_t i)
{
	int		start;
	int		end;
	size_t	offset;

	start = pattern[0] == '*' ? 1 : 0;
	end = pattern[ft_strlen(pattern) - 1] == '*' ? 1 : 0;
	while (parts_pattern[i] && *name)
	{
		offset = 0;
		if ((i == 0 && !start))
			offset = (!ft_strncmp(name, parts_pattern[i],\
			ft_strlen(parts_pattern[i]))) ? ft_strlen(parts_pattern[i]) : -1;
		if ((!parts_pattern[i + 1] && !end))
			if ((name = ft_strnstr(name, parts_pattern[i], ft_strlen(name))))
				offset = (!ft_strncmp(name, parts_pattern[i],\
		ft_strlen(parts_pattern[i]) + 1)) ? ft_strlen(parts_pattern[i]) : -1;
		if (!offset && name)
			name = ft_strnstr(name, parts_pattern[i], ft_strlen(name));
		if (offset == (size_t)-1 || !name)
			return (0);
		name += offset;
		i++;
	}
	return (1);
}

int				ft_wildcard_find_str(char **parts_pattern, char *name,\
															char *pattern)
{
	size_t	i;

	if ((!ft_strchr(pattern, '.') && name[0] == '.') || !ft_strcmp(name, ".")\
													|| !ft_strcmp(name, ".."))
		return (0);
	if (!ft_strcmp(pattern, "*"))
		return (1);
	i = 0;
	return (ft_wildcard_check_name(parts_pattern, name, pattern, i));
}
