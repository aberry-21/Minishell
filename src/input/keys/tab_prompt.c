/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:59:02 by telron            #+#    #+#             */
/*   Updated: 2021/03/02 11:15:55 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_tab_prompt(t_shell *config)
{
	t_cmd_line	*cmd_line;
	t_command	*command;
	t_line		*line_before;
	t_line		*tail;
	size_t		counter;
	t_dlist		*prompt_dlist;
	char 		chr;

	command = ft_input_command_get(config);
	cmd_line = ft_input_cmd_line_get(config);
	ft_input_cursor_sync(config);
	line_before = ft_line_create_str("");
	counter = command->xx_cursor;
	while (counter-- && (chr = cmd_line->line->string[counter]) && (ft_isalnum(chr) || ft_strchr("./_-", chr)))
	{
		ft_line_insert_chr(line_before, chr, 0);
	}
	prompt_dlist = ft_prompt(config, line_before);
	if (ft_dlstsize(prompt_dlist) == 1)
	{
		tail = prompt_dlist->content;
		counter = 0;
		while (tail->string[counter])
			ft_line_insert_chr(cmd_line->line, tail->string[counter++], command->xx_cursor++);
	}
	ft_dlstclear(&prompt_dlist, (void (*)(void*))ft_line_del);
	ft_line_del(line_before);
}
