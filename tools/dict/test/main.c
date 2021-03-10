/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:17:19 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 05:36:36 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_test.h"
#include <printf.h>

int		main(void)
{
	t_dict		*dict = ft_dict_init_pro(128);
	char		*value;
	const char	*key;

	ft_dict_add(&dict, "1", "one");
	printf("%zu %zu \n", dict->count_elem, dict->max_elem);
	ft_dict_add(&dict, "2", "two");
	printf("%zu %zu \n", dict->count_elem, dict->max_elem);
	ft_dict_add(&dict, "3", "three");
	printf("%zu %zu \n", dict->count_elem, dict->max_elem);
	ft_dict_add(&dict, "4", "four");
	printf("%zu %zu \n", dict->count_elem, dict->max_elem);
	ft_dict_add(&dict, "5", "five");
	printf("%zu %zu \n", dict->count_elem, dict->max_elem);
	ft_dict_add(&dict, "6", "six");
	printf("%zu %zu \n", dict->count_elem, dict->max_elem);
	ft_dict_add(&dict, "7", "два");
	printf("%zu %zu \n", dict->count_elem, dict->max_elem);
	while ((value = ft_dict_iter_value(dict)) && (key = ft_dict_iter_keys(dict)))
	{
		printf("hash_index -> |%zu|\nkey -> |%s|\nvalue -> |%s|\n", ft_dict_hash_function(key, dict->max_elem), key, value);
	}
	return (0);
}
