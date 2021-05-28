/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:17:19 by telron            #+#    #+#             */
/*   Updated: 2021/03/10 03:01:25 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_test.h"
#include <stdio.h>

int		main(void)
{
	t_dict		*dict;
	char		*value;
	const char	*key;

	dict = ft_dict_init_pro(128);
	ft_dict_add(&dict, "1", "one");
	ft_dict_add(&dict, "2", "two");
	ft_dict_add(&dict, "3", "three");
	ft_dict_add(&dict, "4", "four");
	ft_dict_add(&dict, "5", "five");
	ft_dict_add(&dict, "6", "six");
	ft_dict_add(&dict, "7", "два");
	while ((value = ft_dict_iter_value(dict)) &&\
		(key = ft_dict_iter_keys(dict)))
	{
		printf("hash_index -> |%zu|\nkey -> |%s|\nvalue -> |%s|\n",\
			ft_dict_hash_function(key, dict->max_elem), key, value);
	}
	return (0);
}
