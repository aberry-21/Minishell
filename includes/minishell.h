/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:20:07 by telron            #+#    #+#             */
/*   Updated: 2021/01/14 22:17:43 by telron           ###   ########.fr       */
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

#endif
