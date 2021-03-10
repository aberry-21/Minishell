/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:31:33 by telron            #+#    #+#             */
/*   Updated: 2021/02/20 03:55:34 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_parse_element	\
	*ft_error_handler(\
			t_shell *config,\
			t_parse_element *element,\
			t_line *line,\
			int type)
{
	ft_line_del(line);
	ft_parse_element_destructor(element);
	if (type == 1)
	{
		ft_error_print(config, "ft_parse_build_double_quotes", "malloc", "line");
		config->exit_code = 12;
	}
	else if (type == 2)
	{
		ft_error_print(config, "ft_parse_build_double_quotes", "malloc", "line add");
		config->exit_code = 12;
	}
	else if (type == 3)
	{
		ft_error_print(config, "ft_parse_build_double_quotes", "expected token", "\"");
		config->exit_code = 5;
	}
	else if (type == 4)
	{
		ft_error_print(config, "ft_parse_build_double_quotes", "malloc", "element");
		config->exit_code = 12;
	}
	return (0);
}

t_parse_element			\
	*ft_parse_build_double_quotes(\
			t_shell *config,\
			char **str,\
			t_dlist **dlist)
{
	t_line			*line;
	t_parse_element	*element;

	element = 0;
	if (!(line = ft_line_create_str("")))
		return (ft_error_handler(config, element, line, 1));
	while (**str && **str != '"')
	{
		if (**str == '$')
		{
			element = ft_parse_immutable_create(line);
			ft_dlstadd_right_content(dlist, element);
			line = ft_line_create_str("");
			(*str)++;
			ft_parse_build_variable(config, str, dlist);
			continue ;
		}
		else if (!ft_strncmp(*str, "\\\n", 2))
			(*str)++;
		else
		{
			if (!ft_strncmp(*str, "\\$", 2) ||\
				!ft_strncmp(*str, "\\\"", 2) ||\
				!ft_strncmp(*str, "\\\\", 2))
				(*str)++;
			if (!ft_line_add_chr(line, **str))
				return (ft_error_handler(config, element, line, 2));
		}
		(*str)++;
	}
	if (**str == '"')
		(*str)++;
	else
		return (ft_error_handler(config, element, line, 3));
	if (!(element = ft_parse_immutable_create(line)) ||
		!ft_dlstadd_right_content(dlist, element))
		return (ft_error_handler(config, element, line, 4));
	return (element);
}
