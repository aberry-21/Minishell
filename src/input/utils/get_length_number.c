/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:55:52 by telron            #+#    #+#             */
/*   Updated: 2021/04/24 21:08:48 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_input_get_length_number(size_t number)
{
	size_t	result;
	size_t	counter;

	result = 1;
	counter = 10;
	while (number >= counter)
	{
		counter *= 10;
		result++;
	}
	return (result);
}
