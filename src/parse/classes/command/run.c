/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:31 by telron            #+#    #+#             */
/*   Updated: 2021/02/05 05:40:44 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_variable(t_shell *config, t_parse_element *element, t_dlist *dlist)
{
	char	*str_variable;
	t_line	*line;

	str_variable = ft_env_get(config, element->content.variable.line->string);
	if (str_variable)
	{
		line = ft_dlstright(dlist)->content;
		ft_line_add_str(line, str_variable);
	}
}

static void	ft_string(t_shell *config, t_parse_element *element, t_dlist *dlist)
{
	// char	*string;
	// size_t	counter;
	// t_line	*line;

	// string = element->content.string.line->string;
	// counter = 0;
	// while (string[counter])
	// {
	// 	line = ft_dlstright(dlist)->content;
	// 	if (string[counter] == ' ')
	// 	{
	// 		if (line->length)
	// 		{
	// 			line = ft_line_create_str("");
	// 			ft_dlstadd_right_content(&dlist, line);
	// 		}
	// 		while (string[counter] == ' ')
	// 			counter++;
	// 	}
	// 	if (string[counter])
	// 	{
	// 		line = ft_dlstright(dlist)->content;
	// 		ft_line_add_chr(line, string[counter++]);
	// 	}
	// }
	t_line	*line;

	line = (t_line *)ft_dlstright(dlist)->content;
	ft_line_add_line(line, element->content.string.line);
}

static void	ft_immutable(t_shell *config, t_parse_element *element, t_dlist *dlist)
{
	t_line	*line;

	line = (t_line *)ft_dlstright(dlist)->content;
	ft_line_add_line(line, element->content.immutable.line);
}

static char	**ft_to_argums(t_shell *config, t_dlist *dlist)
{
	size_t	count;
	size_t	counter;
	char	**result;
	t_list	*list;
	t_line	*line;

	// while (dlist)
	// {
	// 	list = ft_parse_wildcard_create(dlist->content);
	// 	ft_dlstinsert(dlist, dlist->right);
	// }
	count = ft_dlstsize(dlist);
	result = ft_calloc(count + 1, sizeof(char *));
	counter = 0;
	dlist = ft_dlstleft(dlist);
	while (counter < count && dlist)
	{
		line = (t_line *)dlist->content;
		if (line->length)
		{
			result[counter] = line->string;
			counter++;
		}
		dlist = dlist->right;
	}
	return (result);
}

void		ft_parse_command_run(t_shell *config, t_stream *stream,\
							t_parse_command *command)
{
	t_dlist			*dlist_string;
	t_parse_element	*element;
	t_line			*line;
	t_executable	executable;
	t_dlist			*dlist_argums;

	dlist_string = command->dlist_string;
	line = ft_line_create_str("");
	dlist_argums = 0;
	ft_dlstadd_right_content(&dlist_argums, line);
	while (dlist_string)
	{
		element = dlist_string->content;
		if (element->type == STRING_CODE)
			ft_string(config, element, dlist_argums);
		if (element->type == IMMUTABLE_CODE)
			ft_immutable(config, element, dlist_argums);
		if (element->type == VARIABLE_CODE)
			ft_variable(config, element, dlist_argums);
		if (element->type == SEPARATOR_CODE)
		{
			line = ft_dlstright(dlist_argums)->content;
			if (line->length)
			{
				line = ft_line_create_str("");
				ft_dlstadd_right_content(&dlist_argums, line);
			}
		}
		dlist_string = dlist_string->right;
	}
	executable.argums = ft_to_argums(config, dlist_argums);
	ft_memcpy(&executable.descriptors, &stream->descriptors, sizeof(t_descriptors));
	stream->exit_code = ft_launch_executable(config, &executable);
}
