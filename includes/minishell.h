/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:20:07 by telron            #+#    #+#             */
/*   Updated: 2021/01/16 21:41:35 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_includes.h"
# include "minishell_structs.h"

# define BUFFER_SIZE 1024


void	ft_input(t_shell *shell);
void	shell(void);
void	ft_reload_signature(t_shell *config);
void	ft_put_line(t_shell *config, t_line *line_command);
int		ft_launch_executable(char *line_command, char *argv[], char *env[]);

#endif
