/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_environment.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 17:09:10 by telron            #+#    #+#             */
/*   Updated: 2021/02/19 22:37:52 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ENVIRONMENT_H
# define MINISHELL_ENVIRONMENT_H

# include "minishell_structs.h"

# define VAR_ATTR_READONLY		0b00000001
# define VAR_ATTR_TO_EXECUTBLE	0b00000010
# define VAR_ATTR_INVISIBLE		0b00000100
# define VAR_ATTR_NOUNSET		0b00001000
# define VAR_ATTR_ISDYNAMIC		0b00010000

typedef struct		s_variable
{
	char			*name;
	char			*value;
	char			*value_for_exe;
	void			*ft_dynamic_value;
	char			attributes;
}					t_variable;

typedef void	(*t_ft_dyn_var)(t_shell *, t_variable *);

t_dict			*ft_env_init(t_shell *config, const char *import_environment[]);

void  			ft_env_oldpwd_reload(t_shell *config);

char			**ft_env_create_env(t_shell *config);

char			*ft_env_var_get_by_user(t_shell *config, char *key);
char			*ft_env_var_get_by_system(t_shell *config, char *key);

t_variable		*ft_env_var_change_by_user(t_shell *config, const char *import_variable);

void			ft_env_var_delone(t_dict *environment, t_variable *variable, char *key);
t_variable		*ft_env_var_new(t_dict **environment, const char *import_variable, size_t index_equally);

void			ft_env_var_init_others(t_shell *config, t_dict **environment, const char *import_variable, size_t index_equally);

void			ft_env_var_init_home(t_shell *config, t_dict **environment, void *ft_dynamic_value);
void			ft_env_var_dv_home(t_shell *config, t_variable *var_home);

void			ft_env_var_init_shlvl(t_shell *config, t_dict **environment, void *ft_dynamic_value);

void			ft_env_var_init_pwd(t_shell *config, t_dict **environment, void *ft_dynamic_value);
void			ft_env_var_dv_pwd(t_shell *config, t_variable *var_pwd);

void			ft_env_var_init_oldpwd(t_shell *config, t_dict **environment, void *ft_dynamic_value);

void			ft_env_var_init_random(t_shell *config, t_dict **environment, void *ft_dynamic_value);
void			ft_env_var_dv_random(t_shell *config, t_variable *var_random);

void			ft_env_var_init_pid(t_shell *config, t_dict **environment, void *ft_dynamic_value);

void			ft_env_var_init_code_exit(t_shell *config, t_dict **environment, void *ft_dynamic_value);
void			ft_env_var_dv_code_exit(t_shell *config, t_variable *var_home);

# define VAR_HOME	{"HOME", ft_env_var_init_home, ft_env_var_dv_home}
# define VAR_SHLVL	{"SHLVL", ft_env_var_init_shlvl, 0}

# define VAR_PWD	{"PWD", ft_env_var_init_pwd, ft_env_var_dv_pwd}
# define VAR_OLDPWD	{"OLDPWD", ft_env_var_init_oldpwd, 0}
# define VAR_RANDOM	{"RANDOM", ft_env_var_init_random, ft_env_var_dv_random}
# define VAR_PID	{"$", ft_env_var_init_pid, 0}
# define VAR_EXIT	{"?", ft_env_var_init_code_exit, ft_env_var_dv_code_exit}

// # define VARS_FIND	{VAR_HOME, VAR_SHLVL, 0}
# define VARS_NEW	{VAR_HOME, VAR_SHLVL, VAR_PWD, VAR_OLDPWD, VAR_RANDOM, VAR_PID, VAR_EXIT, {0, 0, 0}}

#endif
