/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:38:46 by aberry            #+#    #+#             */
/*   Updated: 2021/02/08 16:13:58 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list			*ft_parse_wildcard(t_line *str)
{
	t_list			*result;
	t_line			*pattern;
	t_line			*origin_pattern;

	result = 0;
	if (!ft_strchr(str->string, '*'))
		return (result);
	if (!(pattern = ft_line_create_str(str->string)))
	{
		ft_lstclear(&result, NULL);
		return (result);
	}
	if (!(origin_pattern = ft_line_create_str(str->string)))
	{
		ft_line_del(pattern);
		ft_lstclear(&result, NULL);
		return (result);
	}
	ft_parse_wildcard_recursion(&result, pattern, origin_pattern);
	ft_line_del(origin_pattern);
	return (result);
}
