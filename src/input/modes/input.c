/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 04:53:05 by telron            #+#    #+#             */
/*   Updated: 2021/05/27 19:20:40 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_winsize_was_changed(t_shell *config)
{
	t_view	*view;

	view = &config->view;
	if (ft_memcmp(&(view->saved_winsize.ws_col),\
				&g_winsize.ws_col,\
				sizeof(g_winsize.ws_col)))
		write(1, "\033[2J", 4);
	ft_memcpy(&(view->saved_winsize), &g_winsize, sizeof(struct winsize));
}

static void	ft_read_or_change_winsize(t_shell *config, char *char_buffer)
{
	*char_buffer = 0;
	while (0 >= read(0, char_buffer, 1))
	{
		if (ft_memcmp(&(config->view.saved_winsize),\
						&g_winsize,\
						sizeof(struct winsize)))
		{
			ft_winsize_was_changed(config);
			break ;
		}
	}
}

void		ft_input(t_shell *config)
{
	char	char_buffer;

	ft_input_view_render(config);
	while (1)
	{
		ft_read_or_change_winsize(config, &char_buffer);
		if (config->view.mode & MODE_CHOICE)
		{
			if (ft_choice(config, char_buffer))
			{
				config->view.mode = MODE_INSERT;
				break ;
			}
		}
		else if (config->view.mode & MODE_NOTE)
		{
			if (config->view.mode & MODE_NORMAL)
			{
				ft_note_normal(config, char_buffer);
			}
			else if (ft_note(config, char_buffer))
				break ;
		}
		else if (config->view.mode & MODE_INSERT)
			ft_insert(config, char_buffer);
		else if (config->view.mode & MODE_NORMAL)
			ft_normal(config, char_buffer);
	}
}
