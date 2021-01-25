/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olebedev <olebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:42:43 by telron            #+#    #+#             */
/*   Updated: 2021/01/21 23:05:04 by olebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <ctype.h>
**
** 		int		isalnum(int c);
** INFO:
** 		Если argument удовлетворяет требованиям
** 		ft_isalpha или ft_isdigit
** 		вернётся 1, иначе 0
*/

int		ft_isalnum(int argument)
{
	return (ft_isalpha(argument) || ft_isdigit(argument));
}
