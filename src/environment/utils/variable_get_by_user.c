/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_get_by_user.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 02:09:31 by telron            #+#    #+#             */
/*   Updated: 2021/02/15 18:55:51 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_env_var_get_by_user(t_shell *config, char *key)
{
	t_variable	*variable;

	variable = (t_variable *)ft_dict_get(config->environment, key);
	if (variable && !(variable->attributes & VAR_ATTR_INVISIBLE))
	{
		// printf("|%s|%d|ft_env_var_get_by_user\n", key, variable->attributes & VAR_ATTR_ISDYNAMIC);
		if (variable->attributes & VAR_ATTR_ISDYNAMIC)
			((void (*)(t_shell *, t_variable *))
				variable->ft_dynamic_value)
					(config, variable);
		return (variable->value);
	}
	return (0);
}
