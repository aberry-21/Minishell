/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_home.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:31:05 by telron            #+#    #+#             */
/*   Updated: 2021/01/22 11:31:21 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_line_home(t_shell *config)
{
	ft_input_command_get(config)->xx_cursor = 0;
}
