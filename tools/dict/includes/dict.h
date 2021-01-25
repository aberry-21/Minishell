/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:33:04 by telron            #+#    #+#             */
/*   Updated: 2021/01/13 22:58:12 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <stddef.h>
# include "libft.h"

/*
** Structure
*/

typedef struct		s_dict_elem
{
	const char		*key;
	void			*content;
	void			*next;
}					t_dict_elem;

typedef struct		s_dict
{
	t_dict_elem		**list;
	size_t			count_elem;
	size_t			max_elem;
}					t_dict;

t_dict				*ft_dict_init(void);
t_dict				*ft_dict_init_pro(size_t max_elem);
int					ft_dict_add(t_dict **dict,\
									const char *key,\
									void *content);
void				*ft_dict_get(t_dict *dict, const char *key);
char				**ft_dict_get_keys(t_dict *dict);
void				ft_dict_del(t_dict *dict, const char *key);
void				ft_dict_rem(t_dict *dict);
void				ft_dict_clean(t_dict *dict);
int					ft_dict_double(t_dict **dict);
size_t				ft_dict_hash_function(const char *key, size_t max_elem);
t_dict_elem			*ft_dict_elem_init(const char *key, void *content);
t_dict_elem			*ft_dict_get_elem_by_key(t_dict_elem *elem,\
									const char *key);
void				ft_dict_elem_add_back(t_dict_elem **elem, t_dict_elem *new);

#endif
