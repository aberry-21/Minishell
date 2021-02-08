/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:33:41 by telron            #+#    #+#             */
/*   Updated: 2021/02/07 01:01:11 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_is_redirection(t_parse_element *element)
{
	char	*string;

	if (element->type == SEPARATOR_CODE)
	{
		string = element->content.separator.line->string;
		if (!ft_strcmp(string, ">>"))
			return (1);
		else if (!ft_strcmp(string, ">"))
			return (2);
		else if (!ft_strcmp(string, "<<"))
			return (3);
		else if (!ft_strcmp(string, "<"))
			return (4);
	}
	return (0);
}

t_parse_element	*ft_redirection(t_dlist *command_tokens, t_dlist *tokens, int type)
{
	t_parse_element	*result;
	t_parse_element	*element;
	t_dlist			*dlist;
	t_dlist			*file_name;

	dlist = tokens;
	while (dlist->content)
	{
		element = (t_parse_element *)dlist->content;
		if (element->type != SEPARATOR_CODE || element->content.separator.line->string[0] != ' ')
			break ;
		dlist = dlist->right;
	}
	file_name = 0;
	while (dlist)
	{
		element = (t_parse_element *)dlist->content;
		if (element->type == SEPARATOR_CODE && element->content.separator.line->string[0] == ' ')
			break ;
		ft_dlstadd_right_content(&file_name, dlist->content);
		dlist->content = 0;
		dlist = dlist->right;
	}
	while (dlist)
	{
		ft_dlstadd_right_content(&command_tokens, dlist->content);
		dlist->content = 0;
		dlist = dlist->right;
	}
	result = ft_parse_redirection_create(ft_parse_build_redirection(command_tokens), file_name, type);
	ft_dlstclear(&tokens, 0);
	return (result);
}

t_parse_element	*ft_parse_build_redirection(t_dlist *tokens)
{
	t_dlist			*dlist;
	t_dlist			*command_tokens;
	t_parse_element	*element;
	int				type;

	dlist = tokens;
	command_tokens = 0;
	while (dlist)
	{
		element = dlist->content;
		if ((type = ft_is_redirection(element)))
		{
			dlist->content = 0;
			dlist = dlist->right;
			return (ft_redirection(command_tokens, dlist, type));
		}
		else
		{
			ft_dlstadd_right_content(&command_tokens, element);
			dlist->content = 0;
		}
		dlist = dlist->right;
	}
	ft_dlstclear(&tokens, 0);
	return (ft_parse_build_command(command_tokens));
}

