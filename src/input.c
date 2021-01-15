/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:33:18 by telron            #+#    #+#             */
/*   Updated: 2021/01/14 21:53:11 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
}

void	ft_input(t_shell *config)
{
	char c;
	int	start;
	// t_string *line;

	start = 1;
	set_input_mode();
	atexit(reset_input_mode);
	signal(SIGINT, sighnd);
	signal(SIGTERM, sighnd);
	while(1)
	{
		// Проверяем что мы начинаем обрабатывать новую строчку
		if (start)
		{
			// Обновляем signature (minishell> )
			ft_reload_signature(config);
			write(1, config->signature->line, config->signature->len);
			start = 0;
		}
		read(0, &c, 1);
		if (c == '\n')
		{
			start = 1;
			// ft_put_line(config, line);
		}
		if(c == '\004') // control-D
			break;
		write(1, &c, 1);
	}
}
