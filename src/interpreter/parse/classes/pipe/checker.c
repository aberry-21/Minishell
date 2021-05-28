/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:08 by telron            #+#    #+#             */
/*   Updated: 2021/04/24 18:25:55 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_parse_pipe_checker(\
					t_parse_pipe *pipe)
{
	if (pipe)
	{
		ft_putstr_fd("Pipe(", 1);
		ft_parse_element_checker(pipe->left);
		ft_putstr_fd(", ", 1);
		ft_parse_element_checker(pipe->right);
		ft_putstr_fd(")", 1);
	}
}
