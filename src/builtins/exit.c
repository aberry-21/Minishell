/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:33:37 by telron            #+#    #+#             */
/*   Updated: 2021/03/02 11:17:58 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_builtin_exit(t_shell *config, const char *argv[])
{
	if (argv[1])
	{
		if (argv[2])
		{
			ft_error_print(\
				config,\
				"ft_builtin_exit",\
				"exit",\
				"too many arguments");
			return (1);
		}
		config->exit_code = ft_atoi(argv[1]);
	}
	ft_exit(config);
	return (0);
}
