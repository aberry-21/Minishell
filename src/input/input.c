/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olebedev <olebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:33:18 by telron            #+#    #+#             */
/*   Updated: 2021/01/23 16:44:14 by olebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

struct termios saved_attributes;

void reset_input_mode(void)
{
	tcsetattr(0, TCSANOW, &saved_attributes);
}

void sighnd(int signo)
{
	exit(0);
}

void set_input_mode(void)
{
	struct termios tattr;
	if(!isatty(0))
	{
		fprintf(stderr, "Notaterminal.\n");
		exit(1);
	}
	tcgetattr(0, &saved_attributes);
	memcpy(&tattr, &saved_attributes,sizeof(tattr));
	tattr.c_lflag&= ~(ICANON|ECHO);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &tattr);
	atexit(reset_input_mode);
	signal(SIGINT, sighnd);
	signal(SIGTERM, sighnd);
}

void	ft_left(t_shell *config)
{
	if (config->cursor != 0)
	{
		write(1, "\033[D", 3);
		config->cursor--;
	}
}

void	ft_right(t_shell *config)
{
	t_line *line;

	line = (t_line *)config->input_lines->content;
	if (config->cursor < line->length)
	{
		write(1, "\033[C", 3);
		config->cursor++;
	}
}

void	ft_input_reset(t_shell *config)
{
	size_t	counter;
	t_line *line;

	line = (t_line *)config->input_lines->content;
	counter = 0;
	while (counter++ < config->cursor)
		write(1, "\033[D", 3);
	counter = 0;
	while (counter++ < line->length)
		write(1, " ", 1);
	counter = 0;
	while (counter++ < line->length)
		write(1, "\033[D", 3);
}

void	ft_input_render(t_shell *config)
{
	t_line	*line;
	size_t	counter;

	line = (t_line *)config->input_lines->content;
	write(1, line->string, line->length);
	counter = 0;
	while (counter++ < line->length - config->cursor)
		write(1, "\033[D", 3);
	// config->cursor = line->length;
}

// void	ft_input_cursor(t_shell *config)
// {
// 	while ()
// }

// void	ft_input_reload(t_shell *config)
// {
// 	t_line *line;

// 	line = (t_line *)config->input_lines->content;
// 	ft_input_reset(config, line->length);
// 	ft_input_render(config);
// }

void	ft_input(t_shell *config)
{
	char buff[3];
	int	start;
	t_line *line;

	start = 1;
	set_input_mode();
	while(1)
	{
		// Проверяем что мы начинаем обрабатывать новую строчку
		if (start)
		{
			// Обновляем signature (minishell> )
			ft_reload_signature(config);
			write(1, config->signature->line, config->signature->len);
			line = ft_line_new(16);
			ft_dlstadd_right_content(&(config->input_lines), line);
			config->input_lines = ft_dlstright(config->input_lines);
			start = 0;
			config->cursor = 0;
		}
		read(0, buff, 1);
		if (*buff == '\033')
		{
			read(0, buff + 1, 2);
			if (ft_strncmp("\033[C", buff, 3))
				ft_left(config);
			else if (ft_strncmp("\033[D", buff, 3))
				ft_right(config);
			// else if (ft_strncmp("\033[A", buff, 3))
			// 	up();
			// else if (ft_strncmp("\033[B", buff, 3))
			// 	down();
			continue ;
		}
		if (*buff == '\n')
		{
			start = 1;
			ft_put_line(config, (t_line *)(config->input_lines->content));
			write(1, "\n", 1);
		}
		else if (*buff == '\004') // control-D
			break;
		else if (*buff == 127)
		{
			write(1, "\ndel!", 5);
		}
		else if (ft_isascii(*buff))
		{
			ft_input_reset(config);
			// ft_line_insert_chr((t_line *)(config->input_lines->content), *buff, (int)config->cursor);
			config->cursor += 1;
			ft_input_render(config);
		}
	}
}
