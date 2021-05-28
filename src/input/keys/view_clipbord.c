/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_clipbord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:28:37 by telron            #+#    #+#             */
/*   Updated: 2021/05/04 02:58:11 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_view_clipbord(t_shell *config)
{
	if (config->view.mode_normal.clipboard.count_cmd_lines ||\
		ft_input_cmd_line_new(&config->view.mode_normal.clipboard))
	{
		config->view.canvas = CANVAS_BUFFER;
		config->view.mode = MODE_INSERT;
	}
}
