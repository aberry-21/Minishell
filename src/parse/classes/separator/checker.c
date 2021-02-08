/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:08 by telron            #+#    #+#             */
/*   Updated: 2021/01/29 01:38:37 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_separator_checker(t_parse_separator *separator)
{
	if (separator)
	{
		ft_putstr_fd("Separator(", FD_LOG);
		ft_putstr_fd(separator->line->string, FD_LOG);
		ft_putstr_fd(")", FD_LOG);
	}
}
