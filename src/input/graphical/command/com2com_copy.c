/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com2com_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:00:56 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 19:18:47 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_input_command_com2com_copy(t_shell *config,\
		t_dlist **dlist_destination, t_dlist *dlist_source, size_t count_line)
{
	size_t		copy_line;

	copy_line = 0;
	while (dlist_source && count_line--)
	{
		ft_input_cmd_line_new_to_dlist(dlist_destination);
		if ((*dlist_destination)->right)
			*dlist_destination = (*dlist_destination)->right;
		ft_line_cpy_line(\
			((t_cmd_line *)(*dlist_destination)->content)->line,\
			((t_cmd_line *)dlist_source->content)->line);
		dlist_source = dlist_source->right;
		copy_line++;
	}
	return (copy_line);
}
