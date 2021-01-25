#include "minishell.h"
//argv {"ls" "-la" 0},  filename, 

// argv {"ls" "-la" "filename" ">>" 0},

	// int stdout_fileno = dup(1);
	// int fd = open("txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// int fp2 = dup2(fd, 1);
	// ft_launch_executable("ls", argv, &config);
	// close(fp2);
	// dup2(stdout_fileno, 1);
	// printf("WERTYUIUYTRE");

static size_t	ft_count_str(const char *str, char sep)
{
	size_t counter;

	counter = 0;
	while (*str)
	{
		if (*str != sep && (*(str + 1) == '\0' || *(str + 1) == sep))
			counter++;
		str++;
	}
	return (counter);
}

int		ft_parse_ident(char *identifier, int *mode)
{
	int		fd;

	fd = (identifier[0] == '&') ? -1 : ft_atoi(identifier);
	if (identifier[0] == '>')
		fd = 1;
	*mode = (ft_count_str(identifier, '>') == 2) ? O_APPEND : O_TRUNC;
	return (fd);
}

void	ft_redirection(t_shell *config, char *argv[])
{
	size_t		counter;
	int			old_fd;
	int			new_fd;
	int			fd_tmp;
	int			mode;

	counter = 0;
	while (argv[counter])
		counter++;
	old_fd = ft_parse_ident(argv[counter - 1], &mode); 
	new_fd = open(argv[counter - 2], O_WRONLY | O_CREAT | mode, 0644);
	if (new_fd == -1)
		return ;
	argv[counter - 2] = 0;

	fd_tmp = dup(old_fd);
	dup2(new_fd, old_fd);

	if (counter > 2)
		ft_launch_executable(argv[0], argv, config);
	
	close(old_fd);
	dup2(fd_tmp, old_fd);

	ft_putstr_fd("GOOD\n", 1);
}