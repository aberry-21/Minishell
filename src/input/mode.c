/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 23:24:53 by telron            #+#    #+#             */
/*   Updated: 2021/05/28 13:55:02 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void\
	ft_reset_mode(void)
{
	tcsetattr(0, TCSANOW, &g_saved_attributes);
}

void\
	ft_input_mode(void)
{
	struct termios	tattr;

	ft_memcpy(&tattr, &g_saved_attributes, sizeof(tattr));
	cfsetispeed(&tattr, B57600);
	tattr.c_lflag &= ~(ICANON | ECHO);
	tattr.c_cc[VMIN] = 0;
	tattr.c_cc[VTIME] = 1;
	tcsetattr(0, TCSAFLUSH, &tattr);
}

void\
	ft_sighnd(int signo)
{
	(void)signo;
}

void\
	ft_on_terminal_resize(int n)
{
	(void)n;
	ioctl(fileno(stdout), TIOCGWINSZ, &(g_winsize));
	signal(SIGWINCH, ft_on_terminal_resize);
}

void\
	ft_init_mode(t_view *view)
{
	if (!isatty(0))
	{
		fprintf(stderr, "Notaterminal.\n");
		exit(1);
	}
	tcgetattr(0, &g_saved_attributes);
	signal(SIGINT, ft_sighnd);
	signal(SIGTERM, ft_sighnd);
	signal(SIGTSTP, ft_sighnd);
	signal(SIGWINCH, ft_on_terminal_resize);
	ioctl(fileno(stdout), TIOCGWINSZ, &(g_winsize));
	ft_memcpy(&(view->saved_winsize), &g_winsize, sizeof(struct winsize));
	ft_input_mode();
}
