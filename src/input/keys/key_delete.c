/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 03:40:55 by telron            #+#    #+#             */
/*   Updated: 2021/01/21 14:11:39 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_delete(t_shell *config)
{
	t_command	*command;
	t_cmd_line	*left_cmd_line;

	ft_input_cursor_sync(config);
	command = ft_input_command_get(config);
	if (command->xx_cursor)
	{
		ft_line_del_chr(ft_input_cmd_line_get(config)->line, command->xx_cursor - 1);
		command->xx_cursor--;
	}
	else if (command->dlist_cmd_lines->left)
	{
		left_cmd_line = (t_cmd_line *)command->dlist_cmd_lines->left->content;
		command->xx_cursor = left_cmd_line->line->length;
		ft_line_add_line(\
			left_cmd_line->line,\
			((t_cmd_line *)command->dlist_cmd_lines->content)->line);
		ft_dlstrelation(command->dlist_cmd_lines->left, command->dlist_cmd_lines->right);
		command->dlist_cmd_lines = command->dlist_cmd_lines->left;
		command->count_cmd_lines--;
	}
}
