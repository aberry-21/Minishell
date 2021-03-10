/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_enter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:50:27 by telron            #+#    #+#             */
/*   Updated: 2021/03/02 10:47:15 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_enter(t_shell *config)
{
	char	**str;
	int		exit_code;

	write(1, "\r", 1);
	ft_up(config->view.draw.height);
	str = ft_split(ft_input_cmd_line_get(config)->line->string, ' ');
	ft_reset_mode();
	exit_code = ft_run_cmd_lines(config, -1, 1);
	ft_input_mode();
	if (!exit_code)
		write(1, "\033[46m↴\033[0m\n", 13);
	else
		write(1, "\033[41m↴\033[0m\n", 13);
	write(1, "\r", 1);
	config->view.draw.height = 0;
}
