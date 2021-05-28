/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:58:24 by telron            #+#    #+#             */
/*   Updated: 2021/05/28 14:05:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_note(t_shell *config, char char_buffer)
{
	ft_input_view_clean(&config->view.draw);
	if (char_buffer == '\033')
		ft_input_keys_mode_to_normal(config);
	else if (char_buffer == '\n')
	{
		if (!ft_strcmp(config->view.mode_note.stop_word->string,\
			ft_input_cmd_line_get(config)->line->string))
			return (1);
		ft_input_keys_classic_enter(config);
	}
	else if (char_buffer == '\004')
		ft_input_keys_control_d(config);
	else if (char_buffer == 127)
		ft_input_keys_delete(config);
	else if (char_buffer && ft_isprint(char_buffer))
		ft_input_keys_any_key(config, char_buffer);
	ft_input_view_render(config);
	return (0);
}
