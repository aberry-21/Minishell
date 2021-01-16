/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:32:46 by telron            #+#    #+#             */
/*   Updated: 2021/01/16 02:51:22 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_put_line(t_shell *config, t_line *line_command)
{
	(void)config;
	if (line_command->length)
	{
		write(1, "\n{command(", 10);
		write(1, line_command->string, line_command->length);
		write(1, ")}", 2);
	}
}
