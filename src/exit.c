/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:23:18 by telron            #+#    #+#             */
/*   Updated: 2021/05/27 23:26:49 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 		ft_free_config(t_shell *config)
{
	ft_del_commands(config);
	ft_env_delete_env(config);
	if (config->view.mode_choice.choice.cmd_line)
		ft_dlstiter_all_right(\
			&config->view.mode_choice.choice.cmd_line->transport,\
			(void (*)(void*))ft_input_cmd_line_delone);
	if (config->view.mode_normal.clipboard.cmd_line)
		ft_dlstiter_all_right(\
			&config->view.mode_normal.clipboard.cmd_line->transport,\
			(void (*)(void*))ft_input_cmd_line_delone);
	if (config->view.mode_note.note.cmd_line)
		ft_dlstiter_all_right(\
			&config->view.mode_note.note.cmd_line->transport,\
			(void (*)(void*))ft_input_cmd_line_delone);
}

void		ft_exit(t_shell *config)
{
	if (config->view.mode != MODE_SCRIPT)
		ft_reset_mode();
	ft_save_history(config);
	ft_free_config(config);
	exit((unsigned char)config->exit_code);
}
