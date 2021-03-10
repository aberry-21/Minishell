/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:31 by telron            #+#    #+#             */
/*   Updated: 2021/02/19 23:20:35 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_parse_element_run(\
					t_shell *config,\
					t_stream *stream,\
					t_parse_element *element)
{
	if (element)
	{
		((void (*)(t_shell *, t_stream *, t_parse_element *))element->run)\
						(config, stream, (t_parse_element *)&element->content);
	}
}
