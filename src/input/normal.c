/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 05:05:26 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 17:17:26 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_normal(t_shell *config, char char_buffer)
{
	static void		*set_keys[][2] = SET_KEYS;
	size_t			counter;
	void			**set;
	t_mode_normal	*mode_normal;

	mode_normal = &config->view.mode_normal;
	ft_input_view_clean(&config->view.draw);
	if (ft_isdigit(char_buffer))
	{
		mode_normal->digit_for_normal =\
			mode_normal->digit_for_normal * 10 + (char_buffer - '0');
		ft_input_view_render(config);
		return ;
	}
	mode_normal->input_buffer[mode_normal->buffer_length] = char_buffer;
	mode_normal->buffer_length++;
	counter = 0;
	while (*set_keys[counter])
	{
		// printf("Index |%zu|%p|\n", counter, set_keys[counter]);
		set = set_keys[counter];
		if (!ft_strncmp(mode_normal->input_buffer, set[0], mode_normal->buffer_length))
		{
			if (mode_normal->buffer_length == ft_strlen(set[0]))
			{
				// ft_input_view_clean(config);
				((void (*)(t_shell *))set[1])(config);
				// ft_input_view_render(config);
				break ;
			}
			ft_input_view_render(config);
			return ;
		}
		counter++;
	}
	mode_normal->buffer_length = 0;
	mode_normal->digit_for_normal = 0;
	ft_input_view_render(config);
}
