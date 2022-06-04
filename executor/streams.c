/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   streams.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:37:45 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/20 17:59:31 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/executor.h"

void	close_streams(t_data *data)
{
	close(data->stdin_fd);
	close(data->stdout_fd);
	close(data->tmp_fd);
}

int	reset_streams(t_data *data, t_program *pro_node)
{
	if (data->pipes > 0 && pro_node->next)
	{
		close(data->tmp_fd);
		data->tmp_fd = dup(data->pipe_fd[0]);
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
	}
	if (data->tmp_fd == -1)
		return (-1);
	if (dup2(data->stdin_fd, STDIN_FILENO) == -1)
		return (-1);
	if (dup2(data->stdin_fd, STDOUT_FILENO) == -1)
		return (-1);
	return (0);
}

int	redirect_streams(t_data *data, t_program *pro_node)
{
	if (data->pipes > 0)
	{
		if (pro_node->next)
		{
			if (pipe(data->pipe_fd) == -1)
				exit(EXIT_PIPE_FAILURE);
		}
		if (redirect_pipe(data, pro_node) == -1)
			exit(EXIT_DUP_FAILURE);
	}
	if (pro_node->redir_head)
	{
		if (redirection(data, pro_node) != 0)
			return (-1);
	}
	return (0);
}

int	initialize_streams(t_data *data)
{
	data->stdin_fd = dup(STDIN_FILENO);
	if (data->stdin_fd == -1)
		return (-1);
	data->stdout_fd = dup(STDOUT_FILENO);
	if (data->stdout_fd == -1)
		return (-1);
	data->tmp_fd = dup(STDIN_FILENO);
	if (data->tmp_fd == -1)
		return (-1);
	return (0);
}
