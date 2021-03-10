/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 07:29:53 by telron            #+#    #+#             */
/*   Updated: 2021/03/02 10:58:28 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	\
	ft_add_number(\
			t_line *line,\
			size_t num)
{
	char		*buff;

	buff = ft_itoa(num);
	if (COLOR_DIGIT)
		ft_line_add_str(line, COLOR_DIGIT);
	ft_line_add_str(line, buff);
	if (COLOR_DIGIT)
		ft_line_add_str(line, COLOR_NORMAL);
	free(buff);
}

static void	\
	ft_add_colon(\
			t_line *line)
{
	if (COLOR_COLON)
		ft_line_add_str(line, COLOR_COLON);
	ft_line_add_chr(line, ':');
	if (COLOR_COLON)
		ft_line_add_str(line, COLOR_NORMAL);
}

static void	\
	ft_add_pwd(\
		t_shell *config,\
		t_line *line)
{
	char		*home;
	char		*pwd;
	size_t		counter;
	size_t		len_home;

	home = ft_env_var_get_by_system(config, "HOME");
	pwd = ft_env_var_get_by_system(config, "PWD");
	len_home = home ? ft_strlen(home) : 0;
	if (COLOR_PWD)
		ft_line_add_str(line, COLOR_PWD);
	counter = 0;
	if (pwd && home && len_home && !ft_strncmp(pwd, home, len_home))
	{
		counter = len_home;
		ft_line_add_chr(line, '~');
	}
	if (pwd)
		ft_line_add_str(line, pwd + counter);
	if (COLOR_PWD)
		ft_line_add_str(line, COLOR_NORMAL);
}

void		\
	ft_input_sugnature_render(\
			t_shell *config)
{
	t_command	*command;
	size_t		counter;

	command = ft_input_command_get(config);
	ft_line_del(config->view.signature);
	config->view.signature = ft_line_create_str("<| minishell | LN ");
	ft_add_colon(config->view.signature);
	ft_line_add_str(config->view.signature, " [");
	ft_add_number(config->view.signature, command->index_up_line);
	ft_line_add_str(config->view.signature, "-");
	ft_add_number(config->view.signature, command->index_down_line);
	ft_line_add_str(config->view.signature, "/");
	ft_add_number(config->view.signature, command->count_cmd_lines);
	ft_line_add_str(config->view.signature, "] | CMD ");
	ft_add_colon(config->view.signature);
	ft_line_add_str(config->view.signature, " [");
	ft_add_number(config->view.signature, config->view.index_command);
	ft_line_add_str(config->view.signature, "/");
	ft_add_number(config->view.signature, config->view.count_command);
	ft_line_add_str(config->view.signature, "] | ");
	if (config->view.mode == MODE_INSERT)
		ft_line_add_str(config->view.signature, "INSERT");
	else if (config->view.mode == MODE_NORMAL)
	{
		ft_line_add_str(config->view.signature, "NORMAL[");
		if (config->view.mode_normal.digit_for_normal)
			ft_add_number(config->view.signature, config->view.mode_normal.digit_for_normal);
		counter = 0;
		while (counter < config->view.mode_normal.buffer_length)
		{
			if (ft_isprint(config->view.mode_normal.input_buffer[counter]))
				ft_line_add_chr(config->view.signature, config->view.mode_normal.input_buffer[counter]);
			counter++;
		}
		ft_line_add_str(config->view.signature, "]");
	}
	ft_line_add_str(config->view.signature, " | ");
	ft_add_pwd(config, config->view.signature);
	ft_line_add_str(config->view.signature, " |>");
}
