/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:39:15 by telron            #+#    #+#             */
/*   Updated: 2021/01/29 19:00:40 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_func(size_t index, void *element)
{
	ft_putstr_fd("\t[", FD_LOG);
	ft_putnbr_fd(index, FD_LOG);
	ft_putstr_fd("]{", FD_LOG);
	ft_parse_element_checker(element);
	ft_putstr_fd("}\n", FD_LOG);
}

void	ft_parse_sequence_checker(t_parse_sequence *sequence)
{
	if (sequence)
	{
		ft_putstr_fd("Sequence(\n", FD_LOG);
		ft_dlstiteri(sequence->dlist_element, ft_func);
		ft_putstr_fd(")", FD_LOG);
	}
}
