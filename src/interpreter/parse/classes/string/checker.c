/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:08 by telron            #+#    #+#             */
/*   Updated: 2021/01/29 01:39:44 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_string_checker(t_parse_string *string)
{
	if (string)
	{
		ft_putstr_fd("String(", FD_LOG);
		ft_putstr_fd(string->line->string, FD_LOG);
		ft_putstr_fd(")", FD_LOG);
	}
}
