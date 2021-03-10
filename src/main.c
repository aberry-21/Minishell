/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:33:37 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 15:24:29 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(\
			int argc,\
			const char *argv[],\
			const char **env)
{
	t_shell	config;

	ft_bzero(&config, sizeof(t_shell));
	config.env_origin = env;
	ft_env_init(&config, env);
	if (argc > 1)
	{
		config.view.mode = MODE_SCRIPT;
		ft_script(&config, argv[1]);
	}
	else
		ft_input(&config);
	return (0);
}
