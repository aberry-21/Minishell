/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipboard_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:41:57 by telron            #+#    #+#             */
/*   Updated: 2021/02/01 19:46:20 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_input_keys_clipboard_clear(t_shell *config)
{
	ft_dlstclear(&config->input.clipboard.dlist_cmd_lines,\
		ft_input_cmd_line_delone);
}
