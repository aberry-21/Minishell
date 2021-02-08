/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:05:34 by aberry            #+#    #+#             */
/*   Updated: 2021/02/08 19:09:45 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_wildcard_step(t_line *pattern)
{
	int		step;

	step = ft_strlen_c(pattern->string, '/');
	if (pattern->string[0] != '/' && ft_strncmp(pattern->string, "./", 2))
		step += 1;
	if (pattern->string[pattern->length - 1] == '/')
		step -= 1;
	return (step);
}

int				ft_wildcard_exit(t_line *path, t_line *pattern,\
					t_line *pattern_tmp, char **pattern_array)
{
	ft_delete_strings(pattern_array);
	ft_line_del(path);
	ft_line_del(pattern);
	ft_line_del(pattern_tmp);
	return (0);
}

void			ft_init_variable(t_line **path, char ***pat_arr,\
													t_line **pat_tmp)
{
	*path = 0;
	*pat_arr = 0;
	*pat_tmp = 0;
}

int				ft_add_or_recursion(t_list **res, t_line *path, t_line *tmp,\
																t_line *org_pat)
{
	if (ft_strlen_c(path->string, '/') == ft_wildcard_step(org_pat))
	{
		if (!ft_lstadd_back_content(res, tmp))
		{
			ft_lstclear(res, (void *)ft_line_del);
			return (1);
		}
	}
	else
		ft_parse_wildcard_recursion(res, tmp, org_pat);
	return (0);
}
