/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_for_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:11:53 by aberry            #+#    #+#             */
/*   Updated: 2021/02/07 19:12:50 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_sort_array_str(char **array)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	i = 0;
	while (array[i])
	{
		j = 1 + i;
		while (array[j])
		{
			if (ft_strcmp(array[i], array[j]) > 0)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int		ft_env_print_for_export(t_shell *config)
{
	size_t		i;
	char		**keys;
	char		*value;

	i = 0;
	if(!(keys = ft_dict_get_keys(config->env)))
		return (1);
	ft_sort_array_str(keys);
	while (keys[i])
	{
		value = (char *)ft_dict_get(config->env, keys[i]);
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(keys[i], 1);
		if (value)
		{
			ft_putchar_fd('=', 1);
			ft_putchar_fd('\"', 1);
			ft_putstr_fd(value, 1);
			ft_putchar_fd('\"', 1);
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
	free(keys);
	return (0);
}