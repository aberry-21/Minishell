/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:51:05 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 17:12:34 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

inline t_cmd_line\
	*ft_input_cmd_line_get(\
			t_shell *config)
{
	return (config->view.command->cmd_line);
}
