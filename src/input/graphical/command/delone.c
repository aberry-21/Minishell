/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 23:57:04 by telron            #+#    #+#             */
/*   Updated: 2021/03/02 10:56:16 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void\
	ft_input_command_delone(\
			t_command *command)
{
	ft_dlstiter_all_right(&command->cmd_line->transport,\
		(void (*)(void*))ft_input_cmd_line_delone);
	free(command);
}
