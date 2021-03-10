/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:33:37 by telron            #+#    #+#             */
/*   Updated: 2021/02/28 13:39:21 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_prompt_command(t_shell *config, t_line *line, t_dlist **res)
{
	t_dlist		*tmp_dlst;
	t_dlist		*tmp_dlst_pointer;
	char		**path;
	int			i;

	i = 0;
	if (!(path = ft_split(ft_env_var_get_by_user(config, "PATH"), ':')))
		return (1);
	while (path[i])
	{
		tmp_dlst = ft_find_command_in_path(path[i++], line);
		tmp_dlst_pointer = tmp_dlst;
		if (ft_prompt_command_add_to_dlst(tmp_dlst, res))
		{
			ft_delete_strings(path);
			ft_dlstclear(&tmp_dlst_pointer, (void *)ft_line_del);
			return (1);
		}
		ft_dlstclear(&tmp_dlst_pointer, (void *)ft_line_del);
	}
	ft_delete_strings(path);
	return (0);
}

static int		ft_prompt_directory(t_line *line, t_dlist **res)
{
	t_dlist		*tmp_dlst;
	t_line		*tmp_line;
	t_dir		dir;

	if (!ft_line_add_chr(line, '*'))
		return (1);
	*res = ft_parse_wildcard(line);
	tmp_dlst = *res;
	while (tmp_dlst)
	{
		tmp_line = (t_line*)(tmp_dlst->content);
		if ((dir.dir = opendir(tmp_line->string)))
			if (!ft_line_add_chr(tmp_line, '/'))
				return (1);
		if (dir.dir)
			closedir(dir.dir);
		tmp_dlst = tmp_dlst->right;
	}
	return (0);
}

static void		ft_strcmp_line(t_line *line, t_dlist **res)
{
	t_dlist		*tmp_dlst;
	t_line		*pattern;
	t_line		*tmp_line;
	int			len_line;

	len_line = line->length;
	tmp_dlst = *res;
	pattern = ft_line_create_line((t_line*)(tmp_dlst->content));
	if (!pattern)
		return ;
	while (tmp_dlst)
	{
		tmp_line = (t_line*)(tmp_dlst->content);
		while (ft_strncmp(pattern->string, tmp_line->string,\
											pattern->length))
			ft_line_del_chr(pattern, pattern->length - 1);
		tmp_dlst = tmp_dlst->right;
	}
	ft_dlstclear(res, (void *)ft_line_del);
	while (len_line--)
		ft_line_del_chr(pattern, 0);
	ft_dlstadd_right_content(res, pattern);
}

t_dlist			*ft_prompt(t_shell *config, t_line *line)
{
	t_dlist		*res;
	t_line		*line_copy;

	res = 0;
	if (!(line_copy = ft_line_create_str(line->string)))
		return (res);
	if (line_copy->string[0] == '.' || line_copy->string[0] == '/')
		while (!ft_isascii(line_copy->string[0]))
			ft_line_del_chr(line_copy, 0);
	if (ft_prompt_directory(line_copy, &res))
		ft_dlstclear(&res, (void *)ft_line_del);
	if (ft_env_var_get_by_user(config, "PATH"))
		if (ft_prompt_command(config, line_copy, &res))
			ft_dlstclear(&res, (void *)ft_line_del);
	if (res)
		ft_strcmp_line(line, &res);
	ft_line_del(line_copy);
	return (res);
}
