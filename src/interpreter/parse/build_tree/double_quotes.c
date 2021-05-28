/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:31:33 by telron            #+#    #+#             */
/*   Updated: 2021/05/13 14:16:09 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_parse_element	\
	*ft_error_handler(\
			t_shell *config,\
			t_line *line,\
			int type)
{
	static const	char name_funcrion[] = "ft_parse_build_double_quotes";

	ft_line_del(line);
	if (type == 1 || type == 2 || type == 4)
		config->exit_code = 12;
	else if (type == 3)
		config->exit_code = 5;
	if (type == 1)
		ft_error_print(config, name_funcrion, "malloc", "line");
	else if (type == 2)
		ft_error_print(config, name_funcrion, "malloc", "line add");
	else if (type == 3)
		ft_error_print(config, name_funcrion, "expected token", "\"");
	else if (type == 4)
		ft_error_print(config, name_funcrion, "malloc", "element");
	return (0);
}

static t_parse_element	\
	*ft_add_to_dlist_new_element(\
			t_line *line,\
			t_dlist **dlist)
{
	t_parse_element	*element;

	element = ft_parse_immutable_create(line);
	if (!element)
		return (0);
	if (ft_dlstadd_right_content(dlist, element))
		return (element);
	ft_parse_element_destructor(element);
	return (0);
}

static int				\
	ft_main_process(\
		t_shell *config,\
		char **str,\
		t_dlist **dlist,\
		t_line **line)
{
	if (**str == '$')
	{
		(*str)++;
		if (ft_add_to_dlist_new_element(*line, dlist) &&\
			(*line = ft_line_create_str("")) &&\
			ft_parse_build_variable(config, str, dlist))
			return (0);
		ft_error_handler(config, *line, 4);
		return (-1);
	}
	else if (!ft_strncmp(*str, "\\\n", 2))
		(*str)++;
	else
	{
		if ((*str)[0] == '\\' && ft_strchr("$\"\\", (*str)[1]))
			(*str)++;
		if (!ft_line_add_chr(*line, **str))
		{
			ft_error_handler(config, *line, 2);
			return (-1);
		}
	}
	(*str)++;
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

	if (!(line = ft_line_create_str("")))
		return (ft_error_handler(config, line, 1));
	while (**str && **str != '"')
	{
		if (ft_main_process(config, str, dlist, &line))
			return (0);
	}
	if (**str != '"')
		return (ft_error_handler(config, line, 3));
	(*str)++;
	if (!(element = ft_add_to_dlist_new_element(line, dlist)))
		return (ft_error_handler(config, line, 4));
	return (element);
}
