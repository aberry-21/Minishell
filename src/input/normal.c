/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 05:05:26 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 06:34:25 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_normal(t_shell *config, char char_buffer)
{
	static void		*set_keys[][2] = SET_KEYS;
	size_t			counter;
	void			**set;

	if (ft_isdigit(char_buffer))
	{
		config->input.digit_for_normal =\
			config->input.digit_for_normal * 10 + (char_buffer - '0');
		return ;
	}
	config->input.input_buffer[config->input.buffer_length] = char_buffer;
	config->input.buffer_length++;
	counter = 0;
	// write(FD_LOG, "\n", 1);
	// write(FD_LOG, config->input.input_buffer, config->input.buffer_length);
	while (*set_keys[counter])
	{
		// printf("Index |%zu|%p|\n", counter, set_keys[counter]);
		set = set_keys[counter];
		if (!ft_strncmp(config->input.input_buffer, set[0], config->input.buffer_length))
		{
			if (config->input.buffer_length != ft_strlen(set[0]))
				return ;
			ft_input_window_clean(config);
			((void (*)(t_shell *))set[1])(config);
			ft_input_window_render(config);
			config->input.buffer_length = 0;
			config->input.digit_for_normal = 0;
		}
		counter++;
	}
	config->input.buffer_length = 0;
	config->input.digit_for_normal = 0;
}
