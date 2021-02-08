/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 00:00:54 by telron            #+#    #+#             */
/*   Updated: 2021/02/02 00:26:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_line_delete(t_shell *config)
{
	t_dlist		*dlist;
	size_t		count_line;
	t_command	*command;

	command = ft_input_command_get(config);
	dlist = command->dlist_cmd_lines;
	count_line = config->input.digit_for_normal;
	if (!count_line)
		count_line++;
	ft_input_keys_line_to_clipboard(config);
	while (dlist && count_line--)
	{
		if (dlist->right)
			command->dlist_cmd_lines = dlist->right;
		else
		{
			command->dlist_cmd_lines = dlist->left;
			count_line = 0;
		}
		ft_dlstrelation(dlist->left, dlist->right);
		ft_dlstdelone(dlist, ft_input_cmd_line_delone);
		command->count_cmd_lines--;
		dlist = command->dlist_cmd_lines;
	}
	if (!command->dlist_cmd_lines)
		ft_input_cmd_line_new(command);
}
