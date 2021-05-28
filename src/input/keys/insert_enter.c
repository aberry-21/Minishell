/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_enter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:20:52 by telron            #+#    #+#             */
/*   Updated: 2021/05/01 16:28:07 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_insert_enter(t_shell *config)
{
	ft_input_keys_enter_line(config);
	ft_input_keys_cursor_down(config);
	ft_input_keys_line_end(config);
}
