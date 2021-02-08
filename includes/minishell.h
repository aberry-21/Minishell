/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:20:07 by telron            #+#    #+#             */
/*   Updated: 2021/02/08 19:36:25 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_includes.h"
# include "minishell_global_variables.h"
# include "minishell_structs.h"
# include "minishell_parse.h"
# include "key_setting.h"

void		shell(void);

int			ft_launch_executable(t_shell *config, t_executable *executable);

void		ft_put_line(t_shell *config, t_line *line_command);

void		ft_input(t_shell *shell);
void		ft_init_mode(t_shell *config);
void		ft_reset_mode(void);
void		ft_input_mode(void);

void		ft_normal(t_shell *config, char char_buffer);
void		ft_insert(t_shell *config, char char_buffer);

void		ft_input_sugnature_render(t_shell *config);

int			ft_env_from_pp_chr(t_shell *config, char *env[]);
char		*ft_env_get(t_shell *config, char *key);
int			ft_env_check_key(t_dict *dict, char *key);
int			ft_env_print(t_shell *config);
char		**ft_env_dict_to_string(t_shell *config);
int			ft_env_print_for_export(t_shell *config);
int			ft_env_clear(t_shell *config);
int			ft_env_del(t_shell *config, char *key);
int			ft_env_change_value(t_shell *config, char *new_value, char *key);
void		ft_delete_strings(char **strings);


void		ft_input_window_render(t_shell *config);
void		ft_input_window_clean(t_shell *config);

t_command	*ft_input_command_get(t_shell *config);
t_command	*ft_input_command_new(t_shell *config);
void		ft_input_command_render(t_shell *config);
void		ft_input_command_reload_count_lines(t_command *command);
void		ft_input_command_reload_len_prefix(t_command *command);
size_t		ft_input_command_com2com_copy(t_shell *config,\
				t_dlist **dlist_destination, t_dlist *dlist_source,\
				size_t count_line);

t_cmd_line	*ft_input_cmd_line_new(t_command *command);
t_cmd_line	*ft_input_cmd_line_new_up(t_command *command);
t_cmd_line	*ft_input_cmd_line_new_to_dlist(t_dlist **dlist);
t_cmd_line	*ft_input_cmd_line_get(t_shell *config);
size_t		ft_input_cmd_line_get_count_lines(t_cmd_line *cmd_line, size_t index);
void		ft_input_cmd_line_delone(t_cmd_line *cmd_line);

t_output_line	*ft_input_output_line_new(t_line *line, size_t index,\
											size_t start, size_t stop);
void			ft_input_output_line_delete(t_output_line *output_line);

void		ft_input_cursor_sync(t_shell *config);
size_t		ft_input_get_length_number(size_t number);

t_list		*ft_parse_wildcard(t_line *str);
int			ft_parse_wildcard_recursion(t_list **res, t_line *pat, t_line *org_pat);
char		**ft_wildcard_set_pattern_array(t_line *pattern, t_line **pattern_tmp);
int			ft_wildcard_find_str(char **parts_pattern, char *name, char *pattern);
int			ft_parse_wildcard_recursion_set_path_and_pattern(t_line **path, t_line **pattern);
size_t		ft_strlen_c(const char *str, const char sep);
int			ft_wildcard_exit(t_line *path, t_line *pattern, t_line *pattern_tmp, char **pattern_array);
void		ft_init_variable(t_line **path, char ***pat_arr, t_line **pat_tmp);
int			ft_add_or_recursion(t_list **res, t_line *path, t_line *tmp, t_line *org_pat);
int			ft_wildcard_step(t_line *pattern);

t_list		*ft_prompt(t_shell *config, t_line *line);
int			ft_prompt_command_add_to_lst(t_list *tmp_lst, t_list **res);
t_list		*ft_find_command_in_path(char *path, t_line *line);

#endif
