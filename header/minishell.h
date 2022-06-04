/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:52 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/23 12:52:44 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "utils.h"
# include "structs.h"
# include "exit.h"
# include "env.h"
# include "tokenizer.h"
# include "parser.h"
# include "executor.h"

# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>

# define ERROR		-1
# define SUCESS		0

/*	HANDLE MINISHELL DATA */
t_data	*create_minishell_data(int argc, char **argv, char **envp);
void	init_minishell_data(t_data *data);
void	free_minishell_data(t_data *data);
void	modify_shlvl(t_data *data);

/*	MINISHELL INPUT */
void	read_minishell_input(t_data *data);
int		check_minishell_input(t_data *data);

/*	MINISHELL */
int		minishell(t_data *data);

#endif