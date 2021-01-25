/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:33:37 by telron            #+#    #+#             */
/*   Updated: 2021/01/25 21:25:21 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char *argv[], char *env[])
{
	t_shell	config;
	char	**data;

	config.env = ft_dict_init();
	char **str = ft_split(argv[1], ' ');//"ls -la | cat -e"
	config.streams = malloc(sizeof(t_stream));
	
	ft_env_collect_dict(&config, env);
	ft_dup_streams(&config);
	//ft_launch_executable("ls", argv, &config);
	// ft_redirection(&config, str, ">", "test");
	ft_pipe(&config, str);
	ft_putendl_fd("GO", 1);
	return (0);
}



