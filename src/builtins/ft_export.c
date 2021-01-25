/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:27:08 by aberry            #+#    #+#             */
/*   Updated: 2021/01/25 21:27:08 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_add_or_change(t_shell *config, char **dict_elem, int flag)
{
	char	*data;

	dict_elem[1] = (!dict_elem[1]) ? ft_strdup("") : dict_elem[1];
	data = (!flag) ? dict_elem[1] : NULL;
	if(ft_env_check_key(config, dict_elem[0]))
	 	ft_dict_add(&(config->env), dict_elem[0], data);
	else if (data)
	 	ft_env_change_value(config, data, dict_elem[0]);
}

static int		ft_check_data(char *str)
{
	size_t	i;
	int		identifier_error;

	i = 0;
	identifier_error = !ft_isalpha(str[0]);
	while (str[i] && !identifier_error)
		identifier_error = !ft_isalnum(str[i++]);
	if (identifier_error)
	{
		ft_putstr_fd("minishell: export: ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": not a valid identifier", 2);
	}
	return (identifier_error);
}

int				ft_set_env(t_shell *config, const char *argv[], int indefier)
{
	char	**dict_elem;
	size_t	i;
	int		flag;
	int		identifier_error;

	i = 0;
	flag = 0;
	if (!argv)
	{
		ft_env_print_for_export(config);
		return (0);
	}
	while (argv[i])
	{
		flag = !ft_strchr(argv[i], '=');
		if(!(dict_elem = ft_split(argv[i++], '=')))
			return (-1);//ft_exit
		if(indefier)
			indefier = ft_check_data((char *)dict_elem[0]);
		if (!indefier)
			ft_add_or_change(config, dict_elem, flag);
		free(dict_elem);
	}
	return (identifier_error);
}

int				ft_export(t_shell *config, const char *argv[])
{
	return (ft_set_env(config, argv, 0));
}