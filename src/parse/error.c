/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:45:30 by telron            #+#    #+#             */
/*   Updated: 2021/02/07 04:32:49 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_print(t_shell *config, const char *func_name,\
							const char *message, const char *info)
{
	write(1, "\033[1;31mmsh\033[1;35m:\033[1;34m", 25);
	if (func_name)
		write(1, func_name, ft_strlen(func_name));
	write(1, "\033[1;35m:\033[1;37m", 15);
	if (message)
		write(1, message, ft_strlen(message));
	write(1, "\033[1;35m:\033[1;34m", 15);
	if (info)
		write(1, info, ft_strlen(info));
	write(1, "\033[m", 3);
}
