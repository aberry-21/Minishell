/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_signature.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:34:05 by telron            #+#    #+#             */
/*   Updated: 2021/01/14 21:34:07 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_reload_signature(t_shell *config)
{
	config->signature = malloc(sizeof(t_string));
	config->signature->line = ft_strdup("minishell> ");
	config->signature->len = ft_strlen(config->signature->line);
}
