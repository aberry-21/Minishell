/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 05:19:00 by telron            #+#    #+#             */
/*   Updated: 2021/02/07 05:04:37 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_line_has_separator(const char *string)
{
	size_t		counter;
	const char	*separator;
	size_t		length_separator;
	static char	*type_separator[15] = {"~", "*", "{ ",\
		"}", ";", "&&", "||", "|", ">>", ">", "<<", "<", "\n", " ", 0};

	counter = 0;
	while (type_separator[counter])
	{
		separator = type_separator[counter];
		length_separator = ft_strlen(separator);
		if (!ft_strncmp(separator, string, length_separator))
			return (length_separator);
		counter++;
	}
	return (0);
}

void	ft_guard(char **str, t_dlist **dlist)
{
	t_line			*line;
	t_parse_element	*element;

	if (**str == '\n')
		(*str)++;
	else if (**str)
	{
		line = ft_line_create_chr(**str);
		element = ft_parse_immutable_create(line);
		ft_dlstadd_right_content(dlist, element);
		(*str)++;
	}
}

void	ft_separator(char **str, t_dlist **dlist, size_t count)
{
	t_line			*line;
	t_parse_element	*element;

	line = ft_line_create_str(ft_substr(*str, 0, count));
	element = ft_parse_separator_create(line);
	ft_dlstadd_right_content(dlist, element);
	(*str) += count;
}

void	ft_string(t_line *line, t_dlist **dlist)
{
	t_parse_element	*element;

	if (line->length)
	{
		element = ft_parse_string_create(line);
		ft_dlstadd_right_content(dlist, element);
	}
}

static void	ft_tokenize(t_shell *config, char **str, t_dlist **dlist)
{
	t_line	*line;
	size_t	count;
	char	chr;

	line = ft_line_create_str("");
	while (**str)
	{
		if (ft_strchr("\\'\"$", **str))
		{
			ft_string(line, dlist);
			line = ft_line_create_str("");
			chr = **str;
			(*str)++;
			if (chr == '\\')
				ft_guard(str, dlist);
			else if (chr == '\'')
				ft_parse_build_quotes(config, str, dlist);
			else if (chr == '"')
				ft_parse_build_double_quotes(config, str, dlist);
			else if (chr == '$')
				ft_parse_build_variable(config, str, dlist);
		}
		else if ((count = ft_line_has_separator(*str)))
		{
			ft_string(line, dlist);
			line = ft_line_create_str("");
			ft_separator(str, dlist, count);
		}
		else
			ft_line_add_chr(line, *(*str)++);
	}
	ft_string(line, dlist);
}

t_dlist		*ft_parse_build_tokenize(t_shell *config, t_line *line)
{
	t_dlist	*dlist;

	dlist = 0;
	ft_tokenize(config, &line->string, &dlist);
	return (dlist);
}
