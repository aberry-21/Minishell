/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:27:05 by aberry            #+#    #+#             */
/*   Updated: 2021/05/28 05:52:29 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void		ft_env_printf(t_shell *config)
// {
// 	size_t			counter;
// 	char			**environment;

// 	environment = ft_env_create_env(config);
// 	counter = 0;
// 	if (!environment)
// 	{
// 		ft_error_print(&config, "env", "malloc", "change or add");
// 		exit(12);
// 	}
// 	while (environment[counter])
// 	{
// 		ft_putendl_fd(environment[counter], 1);
// 		counter++;
// 	}
// 	ft_delete_strings(environment);
// }

// static void		ft_env_exe(t_shell *config, const char *argv[])
// {
// 	t_executable	executable;

// 	executable.descriptors.std_in = 0;
// 	executable.descriptors.std_out = 1;
// 	executable.descriptors.std_err = 2;
// 	executable.argums = argv;
// 	ft_launch_executable(config, &executable);
// }

// int				main(int argc, const char *argv[], const char *env[])
// {
// 	t_shell			config;

// 	ft_bzero(&config, sizeof(t_shell));
// 	config.env_origin = env;
// 	ft_env_init(&config, env);
// 	config.input.mode = MODE_SCRIPT;
// 	argv++;
// 	while (*argv && ft_strchr(*argv, '='))
// 	{
// 		if (!ft_env_var_change_by_user(&config, *argv))
// 		{
// 			ft_error_print(&config, "env", "malloc", "change or add");
// 			exit(12);
// 		}
// 		argv++;
// 		argc--;
// 	}
// 	if (!(argc - 1))
// 		ft_env_printf(&config);
// 	else
// 		ft_env_exe(&config, argv);
// 	return (0);
// }

static t_list	*ft_builtin_env_get_list(t_shell *config)
{
	t_list		*list_vars;
	t_variable	*variable;

	list_vars = 0;
	while ((variable = ft_dict_iter_value(config->environment)))
	{
		if (!(variable->attributes & VAR_ATTR_TO_EXECUTBLE) ||\
			(variable->attributes & VAR_ATTR_INVISIBLE))
			continue ;
		if (variable->attributes & VAR_ATTR_ISDYNAMIC)
			((t_ft_dyn_var)variable->ft_dynamic_value)(config, variable);
		if (variable->value_for_exe)
			ft_lstadd_back_content(&list_vars, variable->value_for_exe);
	}
	return (list_vars);
}

static char	**ft_create_new_env(t_list *list)
{
	char		**result;
	size_t		counter;
	size_t		count;

	count = ft_lstsize(list);
	result = (char **)ft_calloc(count + 1, sizeof(char *));
	counter = 0;
	if (result)
		while (list && counter < count)
		{
			result[counter++] = list->content;
			list = list->next;
		}
	return (result);
}

void		ft_print_new_env(char **new_env)
{
	void	(*func)(const char *, int);
	size_t	index;

	index = 0;
	while (new_env[index])
	{
		if (new_env[index + 1])
			func = ft_putendl_fd;
		else
			func = ft_putstr_fd;
		func(new_env[index], 1);
		index++;
	}
}

int			ft_builtin_env(t_shell *config, char *const argv[])
{
	t_list		*list;
	size_t		index;
	char		**new_env;
	pid_t		cpid;
	int 		status;

	status = 0;
	list = ft_builtin_env_get_list(config);
	index = 1;
	while (argv[index] && ft_strchr(argv[index], '='))
	{
		if (!ft_lstadd_back_content(&list, argv[index]))
		{
			ft_lstclear(&list, 0);
			ft_error_print(config, "env", "malloc", "add new variable");
			return (12);
		}
	}
	new_env = ft_create_new_env(list);
	ft_lstclear(&list, 0);
	if (argv[index])
	{
		if (!(cpid = fork()))
			execve(argv[index], argv + index, new_env);
		waitpid(cpid, &status, 0);
	}
	else
		ft_print_new_env(new_env);
	ft_delete_strings(new_env);
	return (status);
}
