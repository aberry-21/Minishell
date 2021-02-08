/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:13:06 by aberry            #+#    #+#             */
/*   Updated: 2021/02/07 19:13:56 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_env_dict_to_string(t_shell *config)
{
	char		**keys;
	char		*value;
	char		*tmp;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if(!(keys = ft_dict_get_keys(config->env)))
		return ((char **)0);
	while (keys[i])
	{
		value = (char *)ft_dict_get(config->env, keys[i]);
		if(!(tmp = (char *)ft_strjoin(keys[i++], "=")))
			return ((char **)0);
		if (value)
			if(!(keys[j++] = (char *)ft_strjoin(tmp, value)))
				return ((char **)0);
		free(tmp);
	}
	keys[j] = (char *)0;
	return (keys);
}
