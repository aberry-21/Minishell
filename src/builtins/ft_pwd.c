#include "minishell.h"

int		main(void)
{
	char	dir[1024 + 1];

	dir[1024] = 0;
	if(!getcwd(dir, 1024))
		return (1);
	ft_putstr_fd(dir, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}