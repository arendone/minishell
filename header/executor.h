/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:41:09 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 11:38:59 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "utils.h"
# include "structs.h"
# include "exit.h"
# include "env.h"
# include "signals.h"

# include <fcntl.h>

/*	EXECUTOR MAIN */
int		executor(t_data *data);
int		execute_program_node(t_data *dat, t_program *pro_node);
void	execute_cmd(t_data *data, t_program *pro_node);

/*	PROCESSES */
void	execute_child(t_program *pro_node, char **env_array, char *path);
void	execute_parent(void);

/*	REDIRECTIONS */
int		redirection(t_data *data, t_program *program);
int		redirection_right(t_program *program, t_redir *current);
int		doubleredirection(t_program *program, t_redir *current);
int		redirection_left(t_program *program, t_redir *current);

/*	HEREDOC */
int		heredoc(t_data *data, t_program *program, t_redir *current);

/*	PATHFINDING */
char	*get_path(t_env *head, char *cmd);

/*	PIPE */
int		redirect_pipe(t_data *data, t_program *pro_node);

/*	STREAMS */
int		initialize_streams(t_data *data);
void	close_streams(t_data *data);
int		redirect_streams(t_data *data, t_program *pro_node);
int		reset_streams(t_data *data, t_program *pro_node);

#endif