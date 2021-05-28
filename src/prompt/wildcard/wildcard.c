/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:38:46 by aberry            #+#    #+#             */
/*   Updated: 2021/04/24 19:44:13 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*ft_parse_wildcard(t_line *str)
{
	t_dlist			*result;
	t_line			*pattern;
	t_line			*origin_pattern;

	result = 0;
	if (!ft_strchr(str->string, '*'))
		return (result);
	if (!(pattern = ft_line_create_str(str->string)))
	{
		ft_dlstclear(&result, NULL);
		return (result);
	}
	if (!(origin_pattern = ft_line_create_str(str->string)))
	{
		ft_line_del(pattern);
		ft_dlstclear(&result, NULL);
		return (result);
	}
	if (ft_parse_wildcard_recursion(&result, pattern, origin_pattern))
		ft_dlstclear(&result, (void *)ft_line_del);
	ft_line_del(origin_pattern);
	return (result);
}
