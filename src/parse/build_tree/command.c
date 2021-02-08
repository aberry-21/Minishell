/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:33:56 by telron            #+#    #+#             */
/*   Updated: 2021/01/30 22:23:48 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parse_element	*ft_parse_build_command(t_dlist *tokens)
{
	ft_putstr_fd("\nin ft_parse_build_command\n", FD_LOG);
	ft_dlstiter_all_right(tokens, ft_parse_element_checker);
	return (ft_parse_command_create(tokens));
}
