/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_pp_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:34:27 by telron            #+#    #+#             */
/*   Updated: 2021/02/07 19:04:37 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_env_from_pp_chr(t_shell *config, char **env)
{
	t_dict	*dict;
	char	**data;
	size_t	index;

	dict = ft_dict_init();
	index = 0;
	while (env[index])
	{
		if(!(data = ft_split(env[index++], '=')))
			return (1);
		if (*data)
		{
			if (!data[1])
				data[1] = ft_strdup("");
			ft_dict_add(&dict, data[0], data[1]);
		}
		free(data);
	}
	if(!(char *)ft_dict_get(dict, "OLDPWD"))
		ft_dict_add(&dict, ft_strdup("OLDPWD"), NULL);
	config->env = dict;
	return (0);
}
