/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_global_variables.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:05:07 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 08:10:07 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_GLOBAL_VARIABLES_H
# define MINISHELL_GLOBAL_VARIABLES_H

struct winsize	g_winsize;
struct termios	saved_attributes;

#define FD_LOG open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644)

#endif
