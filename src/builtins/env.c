/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:27:05 by aberry            #+#    #+#             */
/*   Updated: 2021/02/17 18:49:23 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_env_printf(t_shell *config)
{
	size_t			counter;
	char			**environment;

	environment = ft_env_create_env(config);
	counter = 0;
	if (!environment)
	{
		ft_error_print(&config, "env", "malloc", "change or add");
		exit(12);
	}
	while (environment[counter])
	{
		ft_putendl_fd(environment[counter], 1);
		counter++;
	}
	ft_delete_strings(environment);
}

static void		ft_env_exe(t_shell *config, const char *argv[])
{
	t_executable	executable;
	
	executable.descriptors.std_in = 0;
	executable.descriptors.std_out = 1;
	executable.descriptors.std_err = 2;
	executable.argums = argv;
	ft_launch_executable(config, &executable);
}

int		main(int argc, const char *argv[], const char *env[])
{
	t_shell			config;

	ft_bzero(&config, sizeof(t_shell));
	config.env_origin = env;
	ft_env_init(&config, env);
	config.input.mode = MODE_SCRIPT;
	argv++;
	while (*argv && ft_strchr(*argv, '='))
	{
		if (!ft_env_var_change_by_user(&config, *argv))
		{
			ft_error_print(&config, "env", "malloc", "change or add");
			exit(12);
		}
		argv++;
		argc--;
	}
	if (!(argc - 1))
		ft_env_printf(&config);
	else
		ft_env_exe(&config, argv);
	return (0);
}
