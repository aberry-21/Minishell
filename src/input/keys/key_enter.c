/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_enter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:50:27 by telron            #+#    #+#             */
/*   Updated: 2021/02/07 03:15:43 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	ft_exec(t_shell *config)
// {
// 	t_command	*command;
// 	t_dlist		*dlist_line;
// 	t_line		*line;

// 	command = (t_command *)config->command_lines->content;
// 	dlist_line = ft_dlstleft(command->dlist);
// 	while (dlist_line)
// 	{
// 		line = (t_line *)dlist_line->content;
// 		ft_putstr_fd("command (", 1);
// 		ft_putstr_fd(line->string, 1);
// 		ft_putendl_fd(")", 1);
// 		dlist_line = dlist_line->right;
// 	}
// }
static void		ft_up(int count)
{
	while (count--)
		write(1, "\033[A", 3);
}

// static void		ft_down(int count)
// {
// 	while (count--)
// 		write(1, "\033[B", 3);
// }

// static void		ft_print_n(int count)
// {
// 	while (count--)
// 		write(1, "\n", 1);
// }

void		ft_input_keys_enter(t_shell *config)
{
	char	**str;
	int		exit_code;
	// char buff[17];
	// int c;
	// (void)config;
	write(1, "\r", 1);
	ft_up(config->height);
	// ft_down(config->draw.lines);
	
	// write(1, "command\nzzzz\ndwhodhw\ndwed", 26);
	str = ft_split(ft_input_cmd_line_get(config)->line->string, ' ');
	// ft_launch_executable(str[0], str, config->env_origin);
	ft_reset_mode();
	// ft_parse_run_command(config, ft_input_command_get(config));
	exit_code = ft_run_cmd_lines(config, -1, 1);
	ft_input_mode();
	if (!exit_code)
		write(1, "\033[46m↴\033[0m\n", 13);
	else
		write(1, "\033[41m↴\033[0m\n", 13);
	

	// ft_input_command_new(config);
	// config->dlist_command = ft_dlstright(config->dlist_command);
	// config->index_command = ft_dlstsize(config->dlist_command);
	// ft_print_n(1);
	// ft_print_n(config->draw.lines);
	// ft_down(g_winsize.ws_row);
	write(1, "\r", 1);
	// config->height = config->draw.lines;
	config->height = 0;
	// ft_exec(config);
	// ft_input_do(config, ft_input_command_init);
}
