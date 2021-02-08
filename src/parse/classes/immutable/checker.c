/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:08 by telron            #+#    #+#             */
/*   Updated: 2021/01/30 21:33:46 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_immutable_checker(t_parse_immutable *immutable)
{
	if (immutable)
	{
		ft_putstr_fd("Immutable(", FD_LOG);
		ft_putstr_fd(immutable->line->string, FD_LOG);
		ft_putstr_fd(")", FD_LOG);
	}
}
