/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olebedev <olebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:20:07 by telron            #+#    #+#             */
/*   Updated: 2021/01/23 22:41:46 by olebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_includes.h"
# include "minishell_structs.h"

# define BUFFER_SIZE 1024
extern int	errno;

void	ft_input(t_shell *shell);
void	shell(void);
void	ft_reload_signature(t_shell *config);
void	ft_put_line(t_shell *config, t_line *line_command);
int		ft_launch_executable(char *line_command, char *argv[], t_shell *config);
void	ft_env_collect_dict(t_shell *config, char *env[]);
void	ft_env_print(t_shell *config);
char	**ft_env_dict_to_string(t_shell *config);
void	ft_env_clear(t_shell *config);
void	ft_env_del(t_shell *config, char *key);
void	ft_env_change_value(t_shell *config, char *new_value, char *key);
void	ft_env_print_for_export(t_shell *config);
int		ft_cd(char *path, t_shell *config);
int		ft_env_check_key(t_shell *config, char *key);
int		ft_export(t_shell *config,const char *argv[]);
int		ft_unset(t_shell *config, const char *argv[]);
int		ft_set_env(t_shell *config, const char *argv[], int indefier);
void	ft_redirection(t_shell *config, char *argv[]);
// int		ft_env(t_shell *config, const char *argv[]);
#endif
