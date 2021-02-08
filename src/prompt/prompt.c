/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:33:37 by telron            #+#    #+#             */
/*   Updated: 2021/02/08 19:34:36 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_prompt_command(t_shell *config, t_line *line, t_list **res)
{
	t_list		*tmp_lst;
	t_list		*tmp_lst_pointer;
	char		**path;
	int			i;

	i = 0;
	if (!(path = ft_split(ft_dict_get(config->env, "PATH"), ':')))
		return (1);
	while (path[i])
	{
		tmp_lst = ft_find_command_in_path(path[i++], line);
		tmp_lst_pointer = tmp_lst;
		if (ft_prompt_command_add_to_lst(tmp_lst, res))
		{
			ft_delete_strings(path);
			ft_lstclear(&tmp_lst_pointer, (void *)ft_line_del);
			return (1);
		}
		ft_lstclear(&tmp_lst_pointer, (void *)ft_line_del);
	}
	ft_delete_strings(path);
	return (0);
}

static int		ft_prompt_directory(t_line *line, t_list **res)
{
	t_list		*tmp_lst;
	t_line		*tmp_line;

	if (!ft_line_add_chr(line, '*'))
		return (1);
	*res = ft_parse_wildcard(line);
	tmp_lst = *res;
	while (tmp_lst)
	{
		tmp_line = (t_line*)(tmp_lst->content);
		if (!ft_line_add_chr(tmp_line, '/'))
			return (1);
		tmp_lst = tmp_lst->next;
	}
	return (0);
}

t_list			*ft_prompt(t_shell *config, t_line *line)
{
	t_list		*res;
	t_line		*line_copy;

	res = 0;
	if (!(line_copy = ft_line_create_str(line->string)))
		return (res);
	if (line_copy->string[0] == '.' || line_copy->string[0] == '/')
	{
		if (ft_prompt_directory(line_copy, &res))
			ft_lstclear(&res, (void *)ft_line_del);
	}
	else if ((char *)ft_dict_get(config->env, "PATH"))
	{
		if (ft_prompt_command(config, line_copy, &res))
			ft_lstclear(&res, (void *)ft_line_del);
	}
	ft_line_del(line_copy);
	return (res);
}


/*
int		main(int argc, char *argv[], char *env[])
{
	t_shell config;
	t_list		*tmp_lst;
	t_list		*res;
	t_line		*tmp_line;

	ft_bzero(&config, sizeof(t_shell));
	config.env_origin = env;
	ft_env_from_pp_chr(&config, env);
	tmp_line = ft_line_create_str(argv[1]);
	// res = ft_parse_wildcard(tmp_line);
	res = ft_prompt(&config, tmp_line);
	ft_line_del(tmp_line);
	tmp_lst = res;
	while (tmp_lst)
	{
		tmp_line = (t_line*)(tmp_lst->content);
		printf("%s ", tmp_line->string);
		tmp_lst = tmp_lst->next;
	}
	ft_lstclear(&res, (void *)ft_line_del);
	res = 0;
	tmp_line = 0;
	sleep(1);
	// ft_input(&config);
	return (0);
}

*/