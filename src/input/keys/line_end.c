/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:55:53 by telron            #+#    #+#             */
/*   Updated: 2021/01/22 11:03:44 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_line_end(t_shell *config)
{
	ft_input_command_get(config)->xx_cursor =\
		ft_input_cmd_line_get(config)->line->length;
}
