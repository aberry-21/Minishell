/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e.balabanov <e.balabanov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:31:26 by telron            #+#    #+#             */
/*   Updated: 2021/02/17 13:00:36 by e.balabanov      ###   ########.fr       */
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

# define B_CD		{"cd", ft_builtin_cd}
# define B_PWD		{"pwd", ft_builtin_pwd}
# define B_EXPORT	{"export", ft_builtin_export}
# define B_ECHO		{"echo", ft_builtin_echo}
# define B_UNSET	{"unset", ft_builtin_unset}
# define B_EXIT		{"exit", ft_builtin_exit}

# define BUILTINS	{B_EXPORT, B_PWD, B_ECHO, B_UNSET, B_EXIT, B_CD, {0, 0}}

#endif
