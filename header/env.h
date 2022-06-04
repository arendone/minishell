/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:14:52 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/20 22:27:48 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "utils.h"
# include "structs.h"
# include "exit.h"

/*	ENV NODE FUNCTIONS */
t_env	*create_env_node(void);
void	fill_env_node(t_env *node, char **key_value_pair);
void	copy_env_node(t_env *copy, t_env *node);
void	free_env_node(t_env *node);

/*	ENV KEY-VALUE-PAIR FUNCTIONS */
char	**create_key_value_pair(char *line);
bool	is_key_valid(char *key);
bool	is_key_existing(t_env *head, char *key);
void	free_key_value_pair(char **key_value_pair);

/*	ENV LIST FUNCTIONS */
t_env	*create_env_list(char **argv);
t_env	*copy_env_list(t_env *head);
t_env	*get_last_env_node(t_env *head);
t_env	*get_keymatch_env_node(t_env *head, char *key);
char	*get_keymatch_value(t_env *head, char *key);
void	add_env_node(t_env *head, char **key_value_pair);
void	replace_env_node(t_env *head, char **key_value_pair);
void	delete_env_node(t_env **head, t_env *node);
void	print_env_list(t_env *head);
void	print_env_list_sorted(t_env *head);
void	free_env_list(t_env *head);
void	update_env_cmd_path(t_data *data, char *path);
void	update_env_pwd(t_data *data);
void	update_env_oldpwd(t_data *data);

/*	ENV ARRAY FUNCTIONS */
char	**create_env_array(t_env *head);
void	print_env_array(char **env_array);
void	free_env_array(char **env_array);

#endif