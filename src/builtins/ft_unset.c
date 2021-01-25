/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:27:14 by aberry            #+#    #+#             */
/*   Updated: 2021/01/25 21:27:14 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_data(char *str)
{
	size_t	i;
	int		identifier_error;

	i = 0;
	identifier_error = !ft_isalpha(str[0]);
	while (str[i] && !identifier_error)
		identifier_error = !ft_isalnum(str[i++]);
	if (identifier_error)
	{
		ft_putstr_fd("minishell: unset: ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": not a valid identifier", 2);
	}
	return (identifier_error);
}

int			ft_unset(t_shell *config, const char *argv[])
{
	size_t	i;
	int		identifier_error;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i])
	{
		identifier_error = ft_check_data((char *)argv[i]);
		ft_env_del(config, (char *)argv[i++]);
	}
	return (identifier_error);
}