/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 21:32:28 by telron            #+#    #+#             */
/*   Updated: 2021/02/07 05:58:06 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_min(size_t first, size_t second)
{
	return (first > second ? second : first);
}

// static void		ft_left(int count)
// {
// 	while (count--)
// 		write(1, "\033[D", 3);
// }

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

static void		ft_right(int count)
{
	while (count--)
		write(1, "\033[C", 3);
}

static void		ft_print_n(int count)
{
	while (count--)
		write(1, "\n", 1);
}

static void		ft_to_line(t_shell *config, int index)
{
	int move;
	
	move = config->draw.yy_global - index;
	if (move < 0)
		ft_down(move * -1);
	if (move > 0)
		ft_up(move);
	config->draw.yy_global = index;
}

static void		ft_print_index(t_shell *config, size_t index)
{
	size_t counter;
	size_t count;

	counter = 0;
	count = ft_input_command_get(config)->len_prefix - ft_input_get_length_number(index) - 4;
	while (counter < count)
	{
		write(1, " ", 1);
		counter++;
	}
	write(1, "[\033[1;33m", 8);
	// write(1, "[", 1);
	ft_putnbr_fd(index, 1);
	// write(1, "]> ", 3);
	write(1, "\033[m]> ", 7);
}

static void		ft_print_line(t_shell *config, size_t global_index, t_output_line *output_line)
{
	ft_to_line(config, global_index);
	if (output_line->is_first_line)
		ft_print_index(config, output_line->index);
	write(1, output_line->line->string + output_line->start, ft_min(output_line->stop - output_line->start, ft_strlen(output_line->line->string + output_line->start)));
	write(1, "\r", 1);
}

static void		ft_print_signature(t_shell *config, size_t global_index, t_line *signature)
{
	ft_to_line(config, global_index);
	write(1, signature->string, signature->length);
	write(1, "\r", 1);
}

static void		ft_pr(t_shell *config, size_t index)
{
	t_output_line	*output_line;
	t_line			*line;
	size_t			counter;
	t_dlist			*dlist;
	char			*buff;

	counter = 0;
	dlist = config->draw.begin;
	while (dlist && counter++ < config->draw.lines)
	{
		output_line = dlist->content;
		ft_print_line(config, index++, output_line);
		dlist = dlist->right;
	}
}

static void		ft_input_init_draw(t_shell *config)
{
	config->draw.lines = (g_winsize.ws_row - 1) / 2;
}

static void		ft_get_begin(t_shell *config)
{
	t_dlist *start;
	t_dlist *stop;
	size_t	counter;
	size_t	old_counter;

	counter = 1;
	start = config->draw.middle;
	stop = config->draw.middle;
	ft_input_command_get(config)->index_down_line = ((t_output_line *)stop->content)->index;
	ft_input_command_get(config)->index_up_line = ((t_output_line *)start->content)->index;
	config->draw.yy_real = 0;
	while (counter < config->draw.lines)
	{
		old_counter = counter;
		if (stop->right)
		{
			counter++;
			config->draw.yy_real++;
			stop = stop->right;
			ft_input_command_get(config)->index_down_line = ((t_output_line *)stop->content)->index;
		}
		if (counter < config->draw.lines && start->left)
		{
			counter++;
			start = start->left;
			ft_input_command_get(config)->index_up_line = ((t_output_line *)start->content)->index;
		}
		if (old_counter == counter)
			break ;
	}
	config->draw.lines = counter;
	config->draw.begin = start;
}

void			ft_input_window_render(t_shell *config)
{
	t_output_line	*middle;
	t_command	*command;

	command = config->dlist_command->content;
	ft_input_command_reload_len_prefix(command);
	ft_input_command_render(config);
	middle = (t_output_line *)config->draw.middle->content;
	config->draw.xx_real = ft_min(command->xx_cursor, ft_input_cmd_line_get(config)->line->length);
	config->draw.xx_real += command->len_prefix;
	config->draw.xx_real %= g_winsize.ws_col;
	ft_input_init_draw(config);
	ft_get_begin(config);
	config->draw.index_sugnature = g_winsize.ws_row - config->draw.lines;
	config->draw.yy_global = g_winsize.ws_row;
	config->draw.xx_global = 0;
	if (config->height < config->draw.lines)
	{
		ft_print_n(config->draw.lines - config->height);
		config->height = config->draw.lines;
	}
	ft_input_sugnature_render(config);
	ft_print_signature(config, config->draw.index_sugnature, config->signature);
	ft_pr(config, config->draw.index_sugnature + 1);
	ft_up(config->draw.yy_real);
	ft_dlstclear(&(config->draw.middle), (void (*)(void *))ft_input_output_line_delete);
	ft_right(config->draw.xx_real);
}