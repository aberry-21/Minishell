/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:33:11 by aberry            #+#    #+#             */
/*   Updated: 2021/05/28 05:53:01 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTINS_H
# define MINISHELL_BUILTINS_H

# include "minishell_structs.h"

int			ft_builtin_cd(t_shell *config, const char *argv[]);
int			ft_builtin_pwd(t_shell *config, const char *argv[]);
int			ft_builtin_export(t_shell *config, const char *argv[]);
int			ft_builtin_echo(t_shell *config, const char *argv[]);
int			ft_builtin_unset(t_shell *config, const char *argv[]);
int			ft_builtin_exit(t_shell *config, const char *argv[]);
int			ft_builtin_env(t_shell *config, char *const argv[]);

# define B_CD		{"cd", ft_builtin_cd}
# define B_PWD		{"pwd", ft_builtin_pwd}
# define B_EXP		{"export", ft_builtin_export}
# define B_ECHO		{"echo", ft_builtin_echo}
# define B_UNSET	{"unset", ft_builtin_unset}
# define B_EXIT		{"exit", ft_builtin_exit}
# define B_ENV		{"env", ft_builtin_env}

# define BUILTINS	{B_EXP, B_PWD, B_ECHO, B_UNSET, B_EXIT, B_CD, B_ENV, {0, 0}}

#endif
