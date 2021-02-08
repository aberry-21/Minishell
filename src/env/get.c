/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:42:59 by telron            #+#    #+#             */
/*   Updated: 2021/02/04 10:02:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_env_get(t_shell *config, char *key)
{
	char	*value;

	value = ft_dict_get(config->env, key);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}
