/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 23:24:53 by telron            #+#    #+#             */
/*   Updated: 2021/02/02 04:37:04 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_reset_mode(void)
{
	tcsetattr(0, TCSANOW, &saved_attributes);
}

void	ft_input_mode(void)
{
	struct termios	tattr;

	ft_memcpy(&tattr, &saved_attributes, sizeof(tattr));
	tattr.c_lflag&= ~(ICANON|ECHO);
	// tattr.c_oflag|= OFILL;
	// tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VMIN] = 0;
	// tattr.c_cc[VTIME] = 0;
	tattr.c_cc[VTIME] = 1;
	tcsetattr(0, TCSAFLUSH, &tattr);
}

void sighnd(int signo)
{
	(void)signo;
	ft_reset_mode();
	exit(0);
}

void on_terminal_resize(int n)
{
	(void)n;
	ioctl(fileno(stdout), TIOCGWINSZ, &(g_winsize));
	signal(SIGWINCH, on_terminal_resize);
}

void	ft_init_mode(t_shell *config)
{
	// struct termios tattr;

	if(!isatty(0))
	{
		fprintf(stderr, "Notaterminal.\n");
		exit(1);
	}
	tcgetattr(0, &saved_attributes);
	// ft_memcpy(&tattr, &saved_attributes, sizeof(tattr));
	// tattr.c_lflag&= ~(ICANON|ECHO);
	// // tattr.c_oflag|= OFILL;
	// // tattr.c_cc[VMIN] = 1;
	// tattr.c_cc[VMIN] = 0;
	// // tattr.c_cc[VTIME] = 0;
	// tattr.c_cc[VTIME] = 1;
	// // cfsetispeed(&tattr, B57600);
	// tcsetattr(0, TCSAFLUSH, &tattr);
	// atexit(reset_input_mode);
	signal(SIGINT, sighnd);
	signal(SIGTERM, sighnd);
	signal(SIGWINCH, on_terminal_resize);
	ioctl(fileno(stdout), TIOCGWINSZ, &(g_winsize));
	ft_memcpy(&(config->saved_winsize), &g_winsize, sizeof(struct winsize));
	ft_input_mode();
	// printf("|%d|%d|\n", g_winsize.ws_xpixel, g_winsize.ws_ypixel);
}
