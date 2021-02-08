/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:27:17 by aberry            #+#    #+#             */
/*   Updated: 2021/02/07 19:22:34 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_delete_strings(char **strings)
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

int		ft_env_clear(t_shell *config)
{
	char		**keys;
	size_t		i;

	if(!(keys = ft_dict_get_keys(config->env)))
		return (1);
	i = 0;
	while (keys[i])
		free((char *)ft_dict_get(config->env, keys[i++]));
	ft_dict_rem(config->env);
	ft_delete_strings(keys);
	return (0);
}

int		ft_env_del(t_shell *config, char *key)
{
	t_dict_elem		*elem;
	size_t			index;
	char			*for_free;

	if(!(char *)ft_dict_get(config->env, key))
		return (1);
	index = ft_dict_hash_function(key, config->env->max_elem);
	elem = ft_dict_get_elem_by_key(((config->env->list)[index]), key);
	free((void *)elem->content);
	for_free = (char *)elem->key;
	ft_dict_del(config->env, key);
	free(for_free);
		return (0);
}

int		ft_env_change_value(t_shell *config, char *new_value, char *key)
{
	t_dict_elem		*elem;
	size_t			index;

	if(!(char *)ft_dict_get(config->env, key))
		return (1);
	index = ft_dict_hash_function(key, config->env->max_elem);
	elem = ft_dict_get_elem_by_key(((config->env->list)[index]), key);
	free(elem->content);
	elem->content = ft_strdup(new_value);
	return (0);
}