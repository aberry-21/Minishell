/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:36:14 by aberry            #+#    #+#             */
/*   Updated: 2021/03/02 11:12:00 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_variable			*ft_env_var_new(t_dict **environment,\
							const char *import_variable, size_t index_equally)
{
	t_variable			*variable;
	char				*key;
	int					free_flag;

	free_flag = 0;
	// Удалить старый variable
	key = ft_substr(import_variable, 0, index_equally);
	if (!key)
		return ((t_variable *)NULL);
	ft_env_var_delone(*environment, 0, key);
	variable = (t_variable *)ft_calloc(1, sizeof(t_variable));
	if (!variable)
	{
		free(key);
		return ((t_variable *)NULL);
	}
	variable->name = key;
	if (index_equally != (size_t)-1)
	{
		variable->value_for_exe = ft_strdup(import_variable);
		variable->value = ft_strdup(import_variable + index_equally + 1);
		if (!variable->value || !variable->value_for_exe)
			free_flag = 1;
	}
	if (free_flag || ft_dict_add(environment, variable->name, variable))
		ft_env_var_delone(*environment, variable, (char *)NULL);
	return (variable);
}
