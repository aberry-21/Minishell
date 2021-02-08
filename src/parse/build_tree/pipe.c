/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:33:44 by telron            #+#    #+#             */
/*   Updated: 2021/02/05 05:23:21 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_parse_element	*ft_create_pipe_tree(t_dlist *commands)
{
	t_parse_element	*result;

	result = commands->content;
	commands = commands->right;
	while (commands)
	{
		result = ft_parse_pipe_create(result, commands->content);
		commands = commands->right;
	}
	return (result);
}

t_parse_element			*ft_parse_build_pipe(t_dlist *tokens)
{
	t_dlist			*commands;
	t_dlist			*buffer;
	t_parse_element	*element;

	commands = 0;
	buffer = 0;
	while (tokens)
	{
		element = (t_parse_element *)tokens->content;
		if (element->type == SEPARATOR_CODE && !ft_strcmp(element->content.separator.line->string, "|"))
		{
			ft_dlstadd_right_content(&commands, ft_parse_build_redirection(buffer));
			buffer = 0;
		}
		else
			ft_dlstadd_right_content(&buffer, element);
		tokens = tokens->right;
	}
	ft_dlstadd_right_content(&commands, ft_parse_build_redirection(buffer));
	
	return (ft_create_pipe_tree(commands));
}
