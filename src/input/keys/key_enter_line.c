/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_enter_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:26:10 by telron            #+#    #+#             */
/*   Updated: 2021/02/07 03:15:13 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static void		ft_up(int count)
{
	while (count--)
		write(1, "\033[A", 3);
}

static void		ft_down(int count)
{
	while (count--)
		write(1, "\033[B", 3);
}

static void		ft_n(int count)
{
	while (count--)
		write(1, "\n", 1);
}

void		ft_input_keys_enter_line(t_shell *config)
{
	char	**str;
	int		exit_code;
	size_t	count_line;

	count_line = config->input.digit_for_normal;
	if (!count_line)
		count_line = 1;
	write(1, "\r", 1);
	ft_up(config->height);
	// ft_down(config->draw.lines);

	// write(1, "command\nzzzz\ndwhodhw\ndwed", 26);
	ft_reset_mode();
	str = ft_split(ft_input_cmd_line_get(config)->line->string, ' ');
	// exit_code = ft_parse_run_cmd_line(config, ft_input_cmd_line_get(config));
	exit_code = ft_run_cmd_lines(config, count_line, 0);
	ft_input_mode(); // Why??
	if (!exit_code)
		write(1, "\033[46m↴\033[0m\n", 13);
	else
		write(1, "\033[41m↴\033[0m\n", 13);
	// ft_launch_executable(str[0], str, config->env_origin);

	// write(1, "\033[46m↴\033[0m\n", 15);
	
	// ft_n(config->height);
	// ft_down(g_winsize.ws_row);
	// ft_up(config->draw.lines);
	// ft_input_command_new(config);
	// config->dlist_command = ft_dlstright(config->dlist_command);
	// config->index_command = ft_dlstsize(config->dlist_command);
	// ft_print_n(1);
	// ft_print_n(config->draw.lines);
	// ft_down(g_winsize.ws_row);
	write(1, "\r", 1);
	// config->height = config->draw.lines;
	config->height = 0;
	config->input.digit_for_normal = 0;
	// ft_exec(config);
	// ft_input_do(config, ft_input_command_init);
}
