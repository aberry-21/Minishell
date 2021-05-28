/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:33:37 by telron            #+#    #+#             */
/*   Updated: 2021/05/28 00:39:02 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_view(t_shell *config)
{
	t_view	*view;

	view = &config->view;
	ft_init_mode(view);
	ft_load_history(config);
	ft_input_keys_command_new(config);
	view->index_command += 1;
	view->mode = MODE_DEFAULT;
	// ft_input_view_render(config);
}

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
	{
		ft_init_view(&config);
		ft_input(&config);
	}
	return (0);
}
