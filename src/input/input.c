/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 04:53:05 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 17:16:51 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	ft_input(t_shell *config)
{
	char	char_buffer;
	ssize_t	ret_read;
	t_view	*view;

	view = &config->view;
	ft_init_mode(view);
	ft_input_command_new(view);
	view->index_command = 1;
	view->mode = MODE_DEFAULT;
	ft_input_view_render(config);
	while (1)
	{
		char_buffer = 0;
		ret_read = read(0, &char_buffer, 1);
		if (0 >= ret_read)
		{
			if (ft_memcmp(&(view->saved_winsize), &g_winsize, sizeof(struct winsize)))
			{
				if (ft_memcmp(&(view->saved_winsize.ws_col), &g_winsize.ws_col, sizeof(g_winsize.ws_col)))
					write(1, "\033[2J", 4);
				ft_memcpy(&(view->saved_winsize), &g_winsize, sizeof(struct winsize));
			}
			else
				continue ;
		}
		
		if (view->mode == MODE_INSERT)
			ft_insert(config, char_buffer);
		else if (view->mode == MODE_NORMAL)
			ft_normal(config, char_buffer);
	}
}
