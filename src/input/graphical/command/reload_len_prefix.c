/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_len_prefix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:26:56 by telron            #+#    #+#             */
/*   Updated: 2021/01/25 09:29:31 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_input_command_reload_len_prefix(t_command *command)
{
	command->len_prefix = ft_input_get_length_number(command->count_cmd_lines) + 4; // len("123") + len("[]> ")
}
