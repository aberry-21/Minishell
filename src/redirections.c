#include "minishell.h"

static void ft_reset_streams(t_shell *config)
{
	dup2(config->streams->std_in, 0);
	dup2(config->streams->std_out, 1);
	dup2(config->streams->std_err, 2);
}

static int ft_mode_open(char *indicator)
{
	if (!ft_strcmp(indicator, ">"))
		return (O_WRONLY | O_CREAT | O_TRUNC);
	if (!ft_strcmp(indicator, ">>"))
		return (O_WRONLY | O_CREAT | O_APPEND);
	if (!ft_strcmp(indicator, "<"))
		return (O_RDONLY);
	return (-1);
}

static void ft_dup_fd(char *indicator, char *filename)
{
	int		stream;
	int		mode;
	int		fd;

	stream = 1;
	mode = ft_mode_open(indicator);
	if (mode == 0x0000)
		stream = 0;
	fd = open(filename, mode, 0644);
	dup2(fd, stream);
}

void	ft_redirection(t_shell *config, char *argv[], char *indicator, char *filename)
{
	ft_dup_fd(indicator, filename);
	if (argv)
		ft_launch_executable(argv[0], argv, config);
	ft_reset_streams(config);
}