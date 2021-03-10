/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:14:01 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 07:21:49 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_init_shell_variable(t_shell *config,\
						t_dict **environment, const char *import_variable)
{
	char		*pointer_equally;
	size_t		length;

	pointer_equally = ft_strchr(import_variable, '=');
	length = pointer_equally ? pointer_equally - import_variable : -1;
	if (length != (size_t)-1)
		ft_env_var_init_others(config, environment, import_variable, length);
}

static void			ft_new_variables(t_shell *config, t_dict **environment)
{
	static void	*list_new_variables[][3] = VARS_NEW;
	size_t		counter;

	counter = 0;
	while (*list_new_variables[counter])
	{
		((void (*)(t_shell *, t_dict **, void *))\
			list_new_variables[counter][1])\
				(config, environment, list_new_variables[counter][2]);
		counter++;
	}
}

t_dict				*ft_env_init(t_shell *config,\
								const char *import_environment[])
{
	size_t	counter;
	t_dict	*environment;

	counter = 0;
	environment = ft_dict_init_pro(16);
	while (import_environment[counter])
	{
		ft_init_shell_variable(\
			config, &environment, import_environment[counter]);
		counter++;
	}
	ft_new_variables(config, &environment);
	config->environment = environment;
	return (environment);
}
