/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:26:37 by aberry            #+#    #+#             */
/*   Updated: 2021/05/18 16:09:01 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_script_run(t_shell *config, t_line *line)
{
	t_parse_element	*element;

	element = ft_parse_build(config, line);
	if (!element)
		return (-1);
	ft_run(config, element);
	ft_parse_element_destructor(element);
	return (0);
}

static int		ft_open_file(t_shell *config, const char *filename)
{
	int				fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_error_print(config, "ft_script", filename, \
												"No such file or directory");
		config->exit_code = 1;
		ft_exit(config);
	}
	return (fd);
}

void			ft_script(t_shell *config, const char *filename)
{
	int				fd;
	int				op_buff;
	char			buff[1024];
	t_line			*line;
	t_line			*prt_line;

	fd = ft_open_file(config, filename);
	if (!(line = ft_line_create_str("")))
	{
		close(fd);
		ft_error_print(config, "ft_script", "malloc", "line");
		ft_exit(config);
	}
	while ((op_buff = read(fd, buff, 1023)) > 0 && !(buff[op_buff] = '\0'))
	{
		if ((prt_line = ft_line_add_str(line, buff)))
			continue;
		ft_error_print(config, "ft_script", "malloc", "line");
		break;
	}
	if (prt_line)
		ft_script_run(config, line);
	close(fd);
	ft_line_del(line);
	ft_exit(config);
}
