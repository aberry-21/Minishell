/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:26:58 by aberry            #+#    #+#             */
/*   Updated: 2021/01/25 21:26:58 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ft_chdir(char *path, t_shell *config)
{
	char	new_pwd[1024 + 1];
	char	*pwd;

	errno = 0;
	if (!(pwd = ft_dict_get(config->env, "PWD")))
		pwd = "";
	if(!chdir(path))
	{
		ft_env_change_value(config, pwd, "OLDPWD");
		if(!getcwd(new_pwd, 1024))
			return (1);
		ft_env_change_value(config, new_pwd, "PWD");
	}
	else
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	return 0; 
}

static int			ft_cd_home(t_shell *config)
{
	char	*home;

	home = ft_dict_get(config->env, "HOME");
	if (home)
	{
		if(!ft_strcmp(home, ""))
			home = ".";
		return (ft_chdir(home, config));
	}
	ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	return (1);
}

static int			ft_cd_oldpwd(t_shell *config)
{
	char	*oldpwd;

	oldpwd = ft_dict_get(config->env, "OLDPWD");
	if (oldpwd)
	{
		ft_putendl_fd(oldpwd, 1);
		if(!ft_strcmp(oldpwd, ""))
			oldpwd = ".";
		return (ft_chdir(oldpwd, config));
	}
	ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
	return (1);
}

int			ft_cd(char *path, t_shell *config)
{
	if (!path || !ft_strcmp(path, "--"))
		ft_cd_home(config);
	else if (!ft_strcmp(path, "-"))
		ft_cd_oldpwd(config);
	else
		ft_chdir(path, config);
	return 0; 
}