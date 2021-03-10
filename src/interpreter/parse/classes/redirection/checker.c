/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:08 by telron            #+#    #+#             */
/*   Updated: 2021/02/19 23:26:16 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_parse_redirection_checker(\
					t_parse_redirection *redirection)
{
	if (redirection)
	{
		ft_putstr_fd("Redirection(", FD_LOG);
		ft_parse_element_checker(redirection->element);
		ft_putstr_fd(")", FD_LOG);
	}
}
