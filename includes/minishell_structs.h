/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:21:37 by telron            #+#    #+#             */
/*   Updated: 2021/02/08 16:03:18 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

# include "minishell_includes.h"

typedef struct			s_command
{
	size_t				count_cmd_lines;
	size_t				index_up_line;
	size_t				index_down_line;
	size_t				xx_cursor;
	size_t				len_prefix;
	t_dlist				*dlist_cmd_lines;
}						t_command;

typedef struct			s_cmd_line
{
	t_line				*line;
}						t_cmd_line;

typedef struct			s_input
{
	char				mode;
	char				input_buffer[32];
	size_t				buffer_length;
	size_t				digit_for_normal;
	t_command			clipboard;
}						t_input;

typedef struct			s_output_line
{
	t_line				*line;
	char				is_first_line;
	size_t				index;
	size_t				start;
	size_t				stop;
}						t_output_line;

typedef struct			s_draw
{
	size_t				lines;
	t_dlist				*begin;
	t_dlist				*middle;
	size_t				columns;
	size_t				index_sugnature;
	int					yy_global;
	int					xx_global;
	int					yy_real;
	int					xx_real;
}						t_draw;

typedef struct			s_shell
{
	char				**env_origin;
	t_dict				*env;

	t_dlist				*dlist_command;
	t_line				*signature;
	size_t				height;
	size_t				count_command;
	size_t				index_command;
	t_draw				draw;
	t_input				input;
	int					exit_code;
	struct winsize		saved_winsize;
}						t_shell;

typedef struct			s_dir
{	
	DIR					*dir;
	struct dirent		*entry;
}						t_dir;

#include "minishell_parse_structs.h"

#endif
