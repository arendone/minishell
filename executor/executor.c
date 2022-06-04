/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:43:12 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 11:12:42 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/executor.h"
#include "../header/builtins.h"

void	execute_cmd(t_data *data, t_program *pro_node)
{
	char	**env_array;
	char	*path;
	pid_t	process;

	path = get_path(data->env_head, pro_node->cmd_argv[0]);
	update_env_cmd_path(data, path);
	env_array = create_env_array(data->env_head);
	process = fork();
	if (process == 0)
		execute_child(pro_node, env_array, path);
	free(path);
	free_env_array(env_array);
}

int	execute_program_node(t_data *data, t_program *pro_node)
{
	if (pro_node->cmd_argv[0] == NULL)
		return (-1);
	if (check_builtin(data, pro_node->cmd_argv[0]))
	{
		update_env_cmd_path(data, NULL);
		execute_builtin(data, pro_node->cmd_argv);
		data->builtin_code = 0;
	}
	else
		execute_cmd(data, pro_node);
	return (0);
}

int	executor(t_data *data)
{
	t_program	*pro_node;

	pro_node = data->pro_head;
	if (initialize_streams(data) == -1)
		exit(EXIT_DUP_FAILURE);
	while (pro_node)
	{
		redirect_streams(data, pro_node);
		if (g_exit_status == 0)
			execute_program_node(data, pro_node);
		if (reset_streams(data, pro_node) == -1)
			exit(EXIT_DUP_FAILURE);
		pro_node = pro_node->next;
	}
	close_streams(data);
	execute_parent();
	return (0);
}
