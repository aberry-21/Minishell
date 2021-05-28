/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:51:05 by telron            #+#    #+#             */
/*   Updated: 2021/05/02 13:35:03 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

inline t_cmd_line\
	*ft_input_cmd_line_get(\
			t_shell *config)
{
	return (ft_input_command_get(config)->cmd_line);
}
