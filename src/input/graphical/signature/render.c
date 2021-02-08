/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 07:29:53 by telron            #+#    #+#             */
/*   Updated: 2021/02/07 06:01:16 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_add_number(t_line *line, size_t num)
{
	char		*buff;

	buff = ft_itoa(num);
	ft_line_add_str(line, buff);
	free(buff);
}

void	ft_input_sugnature_render(t_shell *config)
{
	t_command	*command;
	// size_t		counter;

	command = ft_input_command_get(config);
	ft_line_del(config->signature);
	config->signature = ft_line_create_str("<| minishell | LN \033[1;35m:\033[m [\033[1;33m");
	ft_add_number(config->signature, command->index_up_line);
	ft_line_add_str(config->signature, "\033[m-\033[1;33m");
	ft_add_number(config->signature, command->index_down_line);
	ft_line_add_str(config->signature, "\033[m/\033[1;33m");
	ft_add_number(config->signature, command->count_cmd_lines);
	ft_line_add_str(config->signature, "\033[m] | CMD \033[1;35m:\033[m [\033[1;33m");
	ft_add_number(config->signature, config->index_command);
	ft_line_add_str(config->signature, "\033[m/\033[1;33m");
	ft_add_number(config->signature, config->count_command);
	ft_line_add_str(config->signature, "\033[m] | ");
	if (config->input.mode == MODE_INSERT)
		ft_line_add_str(config->signature, "INSERT");
	else if (config->input.mode == MODE_NORMAL)
	{
		ft_line_add_str(config->signature, "NORMAL");
		// counter = 0;
		// while (counter < config->input.buffer_length)
		// {
		// 	if (ft_isprint(config->input.input_buffer[counter]))
		// 		ft_line_add_chr(config->signature, config->input.input_buffer[counter]);
		// 	counter++;
		// }
		// ft_line_add_str(config->signature, "]");
	}
	ft_line_add_str(config->signature, " |>");
}
