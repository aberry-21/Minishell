/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:16:47 by telron            #+#    #+#             */
/*   Updated: 2021/03/02 11:16:49 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_env_var_dv_code_exit(t_shell *config, t_variable *var_home)
{
	unsigned char	code;

	code = !(config->exit_code % 256) && config->exit_code ?\
		1 : config->exit_code;
	free(var_home->value);
	var_home->value = ft_itoa((unsigned char)code);
}
