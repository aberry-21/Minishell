#include "minishell.h"

static void		ft_delete_strings(char **strings)
{
	size_t counter;

	counter = 0;
	while (strings && strings[counter])
	{
		free(strings[counter]);
		counter++;
	}
	free(strings);
}

int	ft_env_check_key(t_shell *config, char *key)
{
	size_t		i;
	char		**keys;

	i = 0;
	if(!(keys = ft_dict_get_keys(config->env)))
		return (0);//ft_exit
	while (keys[i])
		if (!ft_strcmp(keys[i++], key))
			return (0);
	free(keys);
	return (-1);
}

void	ft_env_print(t_shell *config)
{
	size_t		i;
	char		**keys;
	char		*value;

	i = 0;
	if(!(keys = ft_dict_get_keys(config->env)))
		return ;//ft_exit
	while (keys[i])
	{
		value = (char *)ft_dict_get(config->env, keys[i]);
		if (value)
		{
			ft_putstr_fd(keys[i], 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(value, 1);
			ft_putchar_fd('\n', 1);
		}
		i++;
	}
	free(keys);
}

static void		ft_sort_array_str(char **array)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	i = 0;
	while (array[i])
	{
		j = 1 + i;
		while (array[j])
		{
			if (ft_strcmp(array[i], array[j]) > 0)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_env_print_for_export(t_shell *config)
{
	size_t		i;
	char		**keys;
	char		*value;

	i = 0;
	if(!(keys = ft_dict_get_keys(config->env)))
		return ;//ft_exit
	ft_sort_array_str(keys);
	while (keys[i])
	{
		value = (char *)ft_dict_get(config->env, keys[i]);
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(keys[i], 1);
		if (value)
		{
			ft_putchar_fd('=', 1);
			ft_putchar_fd('\"', 1);
			ft_putstr_fd(value, 1);
			ft_putchar_fd('\"', 1);
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
	free(keys);
}

char	**ft_env_dict_to_string(t_shell *config)
{
	char		**keys;
	char		*value;
	char		*tmp;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if(!(keys = ft_dict_get_keys(config->env)))
		return ((char **)0);// ft_exit()
	while (keys[i])
	{
		value = (char *)ft_dict_get(config->env, keys[i]);
		if(!(tmp = (char *)ft_strjoin(keys[i++], "=")))
			return ((char **)0);//ft_exit
		if (value)
			if(!(keys[j++] = (char *)ft_strjoin(tmp, value)))
				return ((char **)0);//ft_exit
		free(tmp);
	}
	keys[j] = (char *)0;
	return (keys);
}

void	ft_env_clear(t_shell *config)
{
	char		**keys;
	size_t		i;

	if(!(keys = ft_dict_get_keys(config->env)))
		return ;//ft_exit
	i = 0;
	while (keys[i])
		free((char *)ft_dict_get(config->env, keys[i++]));
	ft_dict_rem(config->env);
	ft_delete_strings(keys);
}

void	ft_env_del(t_shell *config, char *key)
{
	t_dict_elem		*elem;
	size_t			index;
	char			*for_free;

	if (ft_env_check_key(config, key))
		return ;
	index = ft_dict_hash_function(key, config->env->max_elem);
	elem = ft_dict_get_elem_by_key(((config->env->list)[index]), key);
	free((void *)elem->content);
	for_free = (char *)elem->key;
	ft_dict_del(config->env, key);
	free(for_free);
}


void	ft_env_change_value(t_shell *config, char *new_value, char *key)
{
	t_dict_elem		*elem;
	size_t			index;

	if (ft_env_check_key(config, key))
		return ;
	
	index = ft_dict_hash_function(key, config->env->max_elem);
	elem = ft_dict_get_elem_by_key(((config->env->list)[index]), key);
	free(elem->content);
	elem->content = ft_strdup(new_value);
}



void	ft_env_collect_dict(t_shell *config, char *env[])
{
	char		**data;
	size_t		i;

	i = 0;
	while (env[i])
	{
		if(!(data = ft_split(env[i++], '=')))
			return ;//ft_exit
		if (*data)
		{
			if (!data[1])
				data[1] = ft_strdup("");
			ft_dict_add(&(config->env), data[0], data[1]);
		}
		free(data);
	}
	ft_dict_add(&(config->env), ft_strdup("OLDPWD"), NULL);
}