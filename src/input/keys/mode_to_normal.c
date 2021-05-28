/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_to_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 05:44:41 by telron            #+#    #+#             */
/*   Updated: 2021/05/27 17:08:34 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_mode_to_normal(t_shell *config)
{
	config->view.mode |= MODE_NORMAL;
	config->view.mode ^= MODE_INSERT;
}
