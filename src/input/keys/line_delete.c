/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 00:00:54 by telron            #+#    #+#             */
/*   Updated: 2021/04/24 21:27:05 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_line_delete(t_shell *config)
{
	t_dlist		*dlist;
	size_t		count_line;
	t_command	*command;

	command = ft_input_command_get(config);
	dlist = &command->cmd_line->transport;
	count_line = config->view.mode_normal.digit_for_normal;
	count_line = !count_line ? 1 : count_line;
	ft_input_keys_line_to_clipboard(config);
	while (dlist && count_line--)
	{
		if (dlist->right)
			command->cmd_line = dlist->right->content;
		else
		{
			command->cmd_line = dlist->left ? dlist->left->content : 0;
			count_line = 0;
		}
		ft_dlstrelation(dlist->left, dlist->right);
		ft_input_cmd_line_delone(dlist->content);
		command->count_cmd_lines--;
		dlist = &command->cmd_line->transport;
	}
	if (!command->count_cmd_lines)
		ft_input_cmd_line_new(command);
}
