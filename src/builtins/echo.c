/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:27:03 by aberry            #+#    #+#             */
/*   Updated: 2021/03/02 11:14:00 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_builtin_echo(t_shell __attribute__((unused)) *config,\
							const char *argv[])
{
	int		counter;
	int		flag;

	counter = 1;
	flag = 1;
	while (argv[counter] && !ft_strncmp(argv[counter], "-n", 2))
	{
		flag = 0;
		if (argv[counter++][2])
			break ;
	}
	while (argv[counter])
	{
		ft_putstr_fd(argv[counter], 1);
		if (argv[counter + 1])
			ft_putchar_fd(' ', 1);
		counter++;
	}
	if (flag)
		ft_putchar_fd('\n', 1);
	return (0);
}
