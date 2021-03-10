/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_add_clipboard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:00:05 by telron            #+#    #+#             */
/*   Updated: 2021/03/02 00:28:35 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void\
	ft_input_keys_line_add_clipboard(\
			t_shell *config)
{
	size_t		count_line;
	t_command	*source_command;

	source_command = ft_input_command_get(config);
	count_line = config->view.mode_normal.digit_for_normal;
	if (!count_line)
		count_line = 1;
	ft_input_command_com2com_copy(\
		&config->view.mode_normal.clipboard,\
		source_command, count_line);
}
