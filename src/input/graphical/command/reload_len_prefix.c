/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_len_prefix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:26:56 by telron            #+#    #+#             */
/*   Updated: 2021/04/24 21:02:18 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void\
	ft_input_command_reload_len_prefix(\
			t_command *command)
{
	command->len_prefix = ft_input_get_length_number(command->count_cmd_lines) \
																			+ 4;
}
