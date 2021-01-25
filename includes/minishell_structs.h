/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:21:37 by telron            #+#    #+#             */
/*   Updated: 2021/01/25 18:05:53 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

# include "minishell_includes.h"

typedef struct	s_string
{
	char		*line;
	size_t		allocation;
	size_t		len;
}				t_string;

// typedef struct	s_line_command
// {
// 	t_string	*string;
// 	int			position;
// }				t_line_command;

typedef struct	s_stream
{
	int			std_in;
	int			std_out;
	int			std_err;
}				t_stream;

typedef struct	s_shell
{
	t_dlist		*input_lines;
	t_list		*command_lines;
	t_string	*signature;
	t_dict		*env;
	t_stream	*streams;
	int			cursor;
}				t_shell;



#endif

