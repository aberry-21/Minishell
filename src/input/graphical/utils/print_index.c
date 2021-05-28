/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:43:26 by aberry            #+#    #+#             */
/*   Updated: 2021/04/24 20:44:23 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		\
	ft_print_index(\
			t_shell *config,\
			size_t index)
{
	size_t counter;
	size_t count;

	counter = 0;
	count = ft_input_command_get(config)->len_prefix -
							ft_input_get_length_number(index) - 4;
	while (counter < count)
	{
		write(1, " ", 1);
		counter++;
	}
	write(1, "[", 1);
	if (COLOR_DIGIT)
		write(1, COLOR_DIGIT, ft_strlen(COLOR_DIGIT));
	ft_putnbr_fd(index, 1);
	if (COLOR_DIGIT)
		write(1, COLOR_NORMAL, ft_strlen(COLOR_NORMAL));
	write(1, "]> ", 3);
}
