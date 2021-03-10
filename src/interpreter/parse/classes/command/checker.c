/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:08 by telron            #+#    #+#             */
/*   Updated: 2021/02/19 23:15:02 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_func_argum(\
					size_t index,\
					void *element)
{
	ft_putstr_fd("[", FD_LOG);
	ft_putnbr_fd(index, FD_LOG);
	ft_putstr_fd("]{", FD_LOG);
	ft_parse_element_checker(element);
	ft_putstr_fd("} ", FD_LOG);
}

static void	ft_func_argums(\
					size_t index,\
					void *element)
{
	ft_putstr_fd("[", FD_LOG);
	ft_putnbr_fd(index, FD_LOG);
	ft_putstr_fd("]{", FD_LOG);
	ft_dlstiteri((t_dlist *)element, ft_func_argum);
	ft_putstr_fd("} ", FD_LOG);
}

void		ft_parse_command_checker(\
					t_parse_command *command)
{
	if (command)
	{
		ft_putstr_fd("Command(", FD_LOG);
		ft_dlstiteri(command->dlist_argums, ft_func_argums);
		ft_putstr_fd(")", FD_LOG);
	}
}
