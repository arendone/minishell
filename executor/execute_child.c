/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:02:50 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 11:12:06 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/executor.h"
#include "../header/builtins.h"

void	execute_child(t_program *pro_node, char **env_array, char *path)
{
	int	exec_code;

	signal(SIGINT, sig_child);
	signal(SIGQUIT, sig_child);
	if (pro_node->cmd_argv[0] != NULL)
	{
		exec_code = execve(path, pro_node->cmd_argv, env_array);
		if (exec_code < 0)
			exit(exit_set_error(path, pro_node->cmd_argv[0]));
	}
	else
		exit(EXIT_SUCCESS);
}
