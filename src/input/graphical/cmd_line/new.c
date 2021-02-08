/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 07:32:43 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 18:53:30 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_line		*ft_input_cmd_line_create(void)
{
	t_cmd_line	*cmd_line;

	cmd_line = (t_cmd_line *)ft_calloc(sizeof(t_cmd_line), 1);
	// if (cmd_line)
	// {
	// 	cmd_line->config = command->config;
	// 	cmd_line->command = command;
	// }
	return (cmd_line);
}

t_cmd_line		*ft_input_cmd_line_new(t_command *command)
{
	t_line		*line;
	t_cmd_line	*new_cmd_line;
	t_dlist		*new_dlst_cmd_line;

	line = ft_line_create_str("");
	if (!line)
		return ((t_cmd_line *)0);
	new_cmd_line = ft_input_cmd_line_create();
	if (!new_cmd_line)
	{
		ft_line_del(line);
		return ((t_cmd_line *)0);
	}
	new_cmd_line->line = line;
	new_dlst_cmd_line = ft_dlstnew(new_cmd_line);
	if (!new_dlst_cmd_line)
	{
		ft_line_del(line);
		free(new_cmd_line);
		return ((t_cmd_line *)0);
	}
	if (!command->dlist_cmd_lines)
		command->dlist_cmd_lines = new_dlst_cmd_line;
	else
		ft_dlstinsert(command->dlist_cmd_lines,\
					new_dlst_cmd_line,\
					command->dlist_cmd_lines->right);
	command->count_cmd_lines += 1;
	// new_cmd_line->up = new_dlst_cmd_line;
	return (new_cmd_line);
}

t_cmd_line		*ft_input_cmd_line_new_up(t_command *command)
{
	t_line		*line;
	t_cmd_line	*new_cmd_line;
	t_dlist		*new_dlst_cmd_line;

	line = ft_line_create_str("");
	if (!line)
		return ((t_cmd_line *)0);
	new_cmd_line = ft_input_cmd_line_create();
	if (!new_cmd_line)
	{
		ft_line_del(line);
		return ((t_cmd_line *)0);
	}
	new_cmd_line->line = line;
	new_dlst_cmd_line = ft_dlstnew(new_cmd_line);
	if (!new_dlst_cmd_line)
	{
		ft_line_del(line);
		free(new_cmd_line);
		return ((t_cmd_line *)0);
	}
	if (!command->dlist_cmd_lines)
		command->dlist_cmd_lines = new_dlst_cmd_line;
	else
	{
		ft_dlstinsert(command->dlist_cmd_lines->left,\
					new_dlst_cmd_line,\
					command->dlist_cmd_lines);
	}
	command->count_cmd_lines += 1;
	// new_cmd_line->up = new_dlst_cmd_line;
	return (new_cmd_line);
}

t_cmd_line		*ft_input_cmd_line_new_to_dlist(t_dlist **dlist)
{
	t_line		*line;
	t_cmd_line	*new_cmd_line;
	t_dlist		*new_dlst_cmd_line;

	line = ft_line_create_str("");
	if (!line)
		return ((t_cmd_line *)0);
	new_cmd_line = ft_input_cmd_line_create();
	if (!new_cmd_line)
	{
		ft_line_del(line);
		return ((t_cmd_line *)0);
	}
	new_cmd_line->line = line;
	new_dlst_cmd_line = ft_dlstnew(new_cmd_line);
	if (!new_dlst_cmd_line)
	{
		ft_line_del(line);
		free(new_cmd_line);
		return ((t_cmd_line *)0);
	}
	if (!*dlist)
		*dlist = new_dlst_cmd_line;
	else
		ft_dlstinsert(*dlist,\
					new_dlst_cmd_line,\
					(*dlist)->right);
	// new_cmd_line->up = new_dlst_cmd_line;
	return (new_cmd_line);
}
