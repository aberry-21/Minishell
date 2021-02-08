/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:51:05 by telron            #+#    #+#             */
/*   Updated: 2021/01/21 10:03:05 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_line	*ft_input_cmd_line_get(t_shell *config)
{
	return (ft_input_command_get(config)->dlist_cmd_lines->content);
}
