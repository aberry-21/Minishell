/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:10:19 by aberry            #+#    #+#             */
/*   Updated: 2021/02/07 19:10:55 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_env_print(t_shell *config)
{
	size_t		i;
	char		**keys;
	char		*value;

	i = 0;
	if(!(keys = ft_dict_get_keys(config->env)))
		return (1);
	while (keys[i])
	{
		value = (char *)ft_dict_get(config->env, keys[i]);
		if (value)
		{
			ft_putstr_fd(keys[i], 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(value, 1);
			ft_putchar_fd('\n', 1);
		}
		i++;
	}
	free(keys);
	return (0);
}
