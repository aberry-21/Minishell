/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_signature.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:34:05 by telron            #+#    #+#             */
/*   Updated: 2021/01/25 21:27:33 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_reload_signature(t_shell *config)
{
	config->signature = malloc(sizeof(t_string));
	config->signature->line = ft_strdup("minishell> ");
	config->signature->len = ft_strlen(config->signature->line);
}
