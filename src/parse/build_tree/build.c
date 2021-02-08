/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:47:48 by telron            #+#    #+#             */
/*   Updated: 2021/02/07 03:54:44 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parse_element	*ft_parse_build(t_shell *config, t_line *line)
{
	t_parse_element	*result;
	t_dlist			*tokens;

	result = 0;
	tokens = 0;
	// ft_putstr_fd("\n\n\n", FD_LOG);
	// ft_putendl_fd(line->string, FD_LOG);
	if ((tokens = ft_parse_build_tokenize(config, line)) &&
		// (tokens = ft_parse_build_immutable(tokens)) &&
		// (tokens = ft_parse_build_variable(tokens)) &&
		// (tokens = ft_parse_build_double_quotes(tokens)) &&
		// (tokens = ft_parse_build_quotes(tokens)) &&
		// (result = ft_parse_build_group(tokens)))
		(result = ft_parse_build_sequence(tokens)))
	{
		// ft_dlst_clear(tokens, ft_parse_element_destructor);
		ft_putstr_fd("\n", FD_LOG);
		ft_parse_element_checker(result);
		// ft_line_del(line);
		return (result);
	}
	// ft_putnbr_fd(tokens, FD_LOG);
	ft_dlstiter_all_right(tokens, ft_parse_element_checker);
	// ft_dlst_clear(tokens, ft_parse_element_destructor);
	// ft_line_del(line);
	return ((t_parse_element *)0);
}
