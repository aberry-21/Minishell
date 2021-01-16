/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:33:37 by telron            #+#    #+#             */
/*   Updated: 2021/01/16 21:44:21 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char *argv[], char *env[])
{
	t_shell config;

	ft_bzero(&config, sizeof(t_shell));
	ft_input(&config);
	/*
	* Вот если потестить хочешь, все что выше закомментируй
	* 
	* ft_launch_executable("ls", argv, env);
	*
	*/
	return (0);
}
