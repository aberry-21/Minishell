/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_executable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:19:14 by aberry            #+#    #+#             */
/*   Updated: 2021/05/18 19:59:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_reload_fd(\
					t_descriptors *fd_saved)
{
	dup2(fd_saved->std_in, 0);
	dup2(fd_saved->std_out, 1);
	dup2(fd_saved->std_err, 2);
	close(fd_saved->std_in);
	close(fd_saved->std_out);
	close(fd_saved->std_err);
}

static void	ft_dup_fd(\
					t_descriptors *fd_saved,\
					t_executable *executable)
{
	fd_saved->std_in = dup(0);
	fd_saved->std_out = dup(1);
	fd_saved->std_err = dup(2);
	dup2(executable->descriptors.std_in, 0);
	dup2(executable->descriptors.std_out, 1);
	dup2(executable->descriptors.std_err, 2);
}

int			ft_is_builtin(\
					t_shell *config,\
					t_executable *executable)
{
	static void		*builtins[][2] = BUILTINS;
	size_t			counter;
	t_descriptors	fd_saved;
	int				exit_code;

	counter = 0;
	while (*builtins[counter])
	{
		if (!ft_strcmp_i((char *)builtins[counter][0], executable->argums[0]))
		{
			ft_dup_fd(&fd_saved, executable);
			if (config->view.mode != MODE_SCRIPT)
				ft_reset_mode();
			exit_code = ((int (*)(t_shell *, const char *[])) \
							builtins[counter][1])(config, executable->argums);
			if (config->view.mode != MODE_SCRIPT)
				ft_input_mode();
			ft_reload_fd(&fd_saved);
			return (exit_code);
		}
		counter++;
	}
	return (-1);
}

static void	ft_print_message_exe(t_shell *config, int status, \
								t_executable *executable)
{
	char			string_exit_code[128];

	if (WIFSIGNALED(status) && WTERMSIG(status))
	{
		ft_put_exit_code(string_exit_code, status);
		ft_error_print(config, "ft_launch_executable", executable->argums[0], \
															string_exit_code);
	}
}

static void	ft_launch_execve(
					t_shell *config,\
					t_executable *executable,
					int *status,
					char *path_bin)
{
	pid_t			cpid;
	t_descriptors	fd_saved;

	ft_dup_fd(&fd_saved, executable);
	if (config->view.mode != MODE_SCRIPT)
		ft_reset_mode();
	if (!(cpid = fork()))
		execve(path_bin, (char *const *)executable->argums, \
											ft_env_create_env(config));
	waitpid(cpid, status, 0);
	ft_print_message_exe(config, *status, executable);
	if (config->view.mode != MODE_SCRIPT)
		ft_input_mode();
	ft_reload_fd(&fd_saved);
}

int			ft_launch_executable(\
					t_shell *config,\
					t_executable *executable)
{
	int				status;
	char			*path_bin;

	if (!executable->argums[0])
		return (0);
	if ((status = ft_is_builtin(config, executable)) != -1)
		return (status);
	if (!(path_bin = ft_find_command(config, executable->argums[0])))
	{
		ft_error_print(config, "ft_launch_executable", \
							executable->argums[0], "command not found");
		return (127);
	}
	ft_launch_execve(config, executable, &status, path_bin);
	free(path_bin);
	return (status);
}
