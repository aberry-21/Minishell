/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:08 by telron            #+#    #+#             */
/*   Updated: 2021/01/29 01:38:19 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_pipe_checker(t_parse_pipe *pipe)
{
	if (pipe)
	{
		ft_putstr_fd("Pipe(", FD_LOG);
		ft_parse_element_checker(pipe->left);
		ft_putstr_fd(", ", FD_LOG);
		ft_parse_element_checker(pipe->right);
		ft_putstr_fd(")", FD_LOG);
	}
}
