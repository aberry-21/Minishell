/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olebedev <olebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:33:37 by telron            #+#    #+#             */
/*   Updated: 2021/01/23 22:36:34 by olebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_delete_strings(char **strings)
{
	size_t counter;

	counter = 0;
	while (strings && strings[counter])
	{
		free(strings[counter]);
		counter++;
	}
	free(strings);
}

int		main(int argc, char *argv[], char *env[])
{
	t_shell	config;
	char	**data;

	config.env = ft_dict_init();

	// ft_bzero(&config, sizeof(t_shell));
	// ft_input(&config);
	/*
	* Вот если потестить хочешь, все что выше закомментируй
	* 
	* ft_launch_executable("ls", argv, env);
	*
	*/
	char **str = ft_split("filename >", ' ');
	ft_env_collect_dict(&config, env);
	
	// int stdout_fileno = dup(1);
	// int fd = open("txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	// int fp2 = dup2(fd, 1);
	// ft_putnbr_fd(fp2, 1);
	// ft_launch_executable("ls", argv, &config);
	// close(-1);
	// dup2(stdout_fileno, fp2);
	// ft_putstr_fd("WERTYUIUYTRE", 1);
	ft_redirection(config, str);
	return (0);
}



