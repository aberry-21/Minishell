/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_add_clipboard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:00:05 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 19:37:48 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_line_add_clipboard(t_shell *config)
{
	size_t		count_line;
	t_command	*source_command;

	source_command = ft_input_command_get(config);
	count_line = config->input.digit_for_normal;
	if (!count_line)
		count_line++;
	config->input.clipboard.count_cmd_lines += ft_input_command_com2com_copy(\
		config, &config->input.clipboard.dlist_cmd_lines,\
		source_command->dlist_cmd_lines, count_line);
	
}
