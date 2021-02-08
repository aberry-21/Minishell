/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_down_to_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 07:20:08 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 07:20:56 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_cursor_down_to_insert(t_shell *config)
{
	ft_input_keys_cursor_down(config);
	ft_input_keys_mode_to_insert(config);
}
