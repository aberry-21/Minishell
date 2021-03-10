/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_right_to_insert.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 06:49:17 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 06:50:24 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_input_keys_cursor_right_to_insert(t_shell *config)
{
	ft_input_keys_cursor_right(config);
	ft_input_keys_mode_to_insert(config);
}
