/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:57:19 by telron            #+#    #+#             */
/*   Updated: 2020/11/01 10:05:17 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	char	arr[15];
	int		counter_arr;
	int		positive;

	counter_arr = 14;
	arr[counter_arr--] = 0;
	positive = num < 0 ? -1 : 1;
	if (!num)
		arr[counter_arr--] = '0';
	while (num)
	{
		arr[counter_arr--] = num % 10 * positive + '0';
		num /= 10;
	}
	if (positive == -1)
		arr[counter_arr--] = '-';
	ft_putstr_fd(arr + counter_arr + 1, fd);
}
