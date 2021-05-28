/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 05:19:00 by telron            #+#    #+#             */
/*   Updated: 2021/04/24 15:10:24 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		\
	ft_error_handler(\
			t_shell *config,\
			t_dlist **dlist,\
			t_line **line,\
			int type)
{
	ft_dlstclear(dlist, (void (*)(void*))ft_parse_element_destructor);
	ft_line_del(*line);
	*line = 0;
	if (type == 1)
	{
		ft_error_print(config, "ft_parse_build_tokenize", "malloc", "line add");
		config->exit_code = 12;
	}
	return ;
}

static int		\
	ft_line_has_separator(\
			const char *string)
{
	size_t		counter;
	const char	*separator;
	size_t		length_separator;
	static char	*type_separator[14] = {"~", "{ ",\
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

static void		\
	ft_tokenize(\
			t_shell *config,\
			char **str,\
			t_dlist **dlist,\
			t_line **line)
{
	size_t					count;
	char					*pnt;
	static char				pattern[] = "\\'\"$";
	static t_parse_element	*(*funcs[])(t_shell *, char **, t_dlist **) = {\
		ft_parse_build_guard, ft_parse_build_quotes,\
		ft_parse_build_double_quotes, ft_parse_build_variable};

	while (**str)
		if ((pnt = ft_strchr(pattern, **str)))
		{
			(*str)++;
			if (!ft_parse_build_string(config, line, dlist) ||\
				!funcs[pnt - pattern](config, str, dlist))
				return (ft_error_handler(config, dlist, line, 0));
		}
		else if ((count = ft_line_has_separator(*str)))
		{
			if (!ft_parse_build_string(config, line, dlist) ||\
				!ft_build_separator(config, str, dlist, count))
				return (ft_error_handler(config, dlist, line, 0));
		}
		else if (!ft_line_add_chr(*line, *(*str)++))
			return (ft_error_handler(config, dlist, line, 1));
	if (!ft_parse_build_string(config, line, dlist))
		return (ft_error_handler(config, dlist, line, 0));
}

t_dlist			\
	*ft_parse_build_tokenize(\
			t_shell *config,\
			t_line *line)
{
	t_dlist	*dlist;
	char	*string;
	t_line	*line_buff;

	dlist = 0;
	string = line->string;
	if (!(line_buff = ft_line_create_str("")))
		return ((t_dlist *)0);
	ft_tokenize(config, &string, &dlist, &line_buff);
	ft_line_del(line_buff);
	return (dlist);
}
