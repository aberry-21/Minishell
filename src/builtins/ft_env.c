#include "minishell.h"

int		main(int argc, char *argv[], char *env[])
{
	t_shell		config;
	size_t		i;
	char		*buf;

	i = 1;
	config.env = ft_dict_init();
	ft_env_collect_dict(&config, env);
	buf = NULL;
	while (argv[i])
	{
		if (!ft_strchr(argv[i], '='))
		{
			buf = ft_strdup(argv[i]);
			argv[i] = (char *)0;
			break ;
		}
		i++;
	}
	ft_set_env(&config, (const char **)argv, 0);
	while (*argv)
		argv++;
	*argv = buf;
	if (buf)
		return (ft_launch_executable(buf, argv, &config));
	else
		ft_env_print(&config);
	return (0);
}