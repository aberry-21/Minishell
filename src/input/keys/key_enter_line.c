/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_enter_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:26:10 by telron            #+#    #+#             */
/*   Updated: 2021/03/02 10:47:37 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void\
	ft_input_keys_enter_line(\
			t_shell *config)
{
	int		exit_code;
	size_t	count_line;

	count_line = config->view.mode_normal.digit_for_normal;
	if (!count_line)
		count_line = 1;
	write(1, "\r", 1);
	ft_up(config->view.draw.height);
	exit_code = ft_run_cmd_lines(config, count_line, 0);
	if (!exit_code)
		write(1, "\033[46m↴\033[0m\n", 13);
	else
		write(1, "\033[41m↴\033[0m\n", 13);
	write(1, "\r", 1);
	config->view.draw.height = 0;
	config->view.mode_normal.digit_for_normal = 0;
}
