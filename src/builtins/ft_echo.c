#include "minishell.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		flag;

	i = 1;
	flag = 1;
	while (argv[i] && !ft_strcmp(argv[i], "-n"))
	{
		flag = 0;
		i++;
	}
	while (i < argc)
	{
		ft_putstr_fd(argv[i], 1);
		if (i++ != argc - 1)
			ft_putchar_fd(' ', 1);
	}
	if (flag)
		ft_putchar_fd('\n', 1);
	return (0);
}

