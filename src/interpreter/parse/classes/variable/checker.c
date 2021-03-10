/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:08 by telron            #+#    #+#             */
/*   Updated: 2021/01/29 01:39:53 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_variable_checker(t_parse_variable *variable)
{
	if (variable)
	{
		ft_putstr_fd("Variable(", FD_LOG);
		ft_putstr_fd(variable->line->string, FD_LOG);
		ft_putstr_fd(")", FD_LOG);
	}
}
