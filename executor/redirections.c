/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:18:26 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/23 11:38:13 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/executor.h"

int	redirection(t_data *data, t_program *program)
{
	t_redir	*current;

	current = program->redir_head;
	while (current)
	{
		if (current->type == REDIRECTION_RIGHT)
		{
			if (redirection_right(program, current) == 1)
				return (1);
		}
		else if (current->type == DOUBLE_REDIRECTION)
		{
			if (doubleredirection(program, current) == 1)
				return (1);
		}
		else if (current->type == REDIRECTION_LEFT)
		{
			if (redirection_left(program, current) == 1)
				return (1);
		}
		else if (heredoc(data, program, current) == 1)
			return (1);
		current = current->next;
	}
	return (0);
}

int	redirection_right(t_program *program, t_redir *current)
{
	program->fd[1] = open(current->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (program->fd[1] == -1)
	{
		error_exit_specified("minishell", current->file,
			"Permission denied", 1);
		return (1);
	}
	dup2(program->fd[1], STDOUT_FILENO);
	close(program->fd[1]);
	return (0);
}

int	doubleredirection(t_program *program, t_redir *current)
{
	program->fd[1] = open(current->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (program->fd[1] == -1)
	{
		error_exit_specified("minishell", current->file,
			"Permission denied", 1);
		return (1);
	}
	dup2(program->fd[1], STDOUT_FILENO);
	close(program->fd[1]);
	return (0);
}

int	redirection_left(t_program *program, t_redir *current)
{
	program->fd[0] = open(current->file, O_RDONLY);
	if (program->fd[0] == -1)
	{
		if (errno == EACCES)
			error_exit_specified("minishell", current->file,
				"Permission denied", 1);
		else
			error_exit_specified("minishell", current->file,
				"No such file or directory", 1);
		return (1);
	}
	dup2(program->fd[0], STDIN_FILENO);
	close(program->fd[0]);
	return (0);
}
