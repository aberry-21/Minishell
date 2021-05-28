/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:37:42 by telron            #+#    #+#             */
/*   Updated: 2021/05/27 19:26:31 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

inline t_command\
	*ft_input_command_get(\
			t_shell *config)
{
	if (config->view.mode & MODE_CHOICE)
		return (&config->view.mode_choice.choice);
	if (config->view.mode & MODE_NOTE)
		return (&config->view.mode_note.note);
	if (config->view.canvas == CANVAS_BUFFER)
		return (&config->view.mode_normal.clipboard);
	return (config->view.command);
}
