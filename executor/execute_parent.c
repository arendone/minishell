/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:02:50 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 13:43:00 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/executor.h"
#include "../header/builtins.h"

static void	set_child_signaled_status(int child_state)
{
	if (WTERMSIG(child_state) == 2)
	{
		ft_printf("\n");
		g_exit_status = 130;
	}
	if (WTERMSIG(child_state) == 3)
	{
		ft_printf("Quit: 3\n");
		g_exit_status = 131;
	}
}

static void	set_child_exit_status(int child_state)
{
	g_exit_status = WEXITSTATUS(child_state);
	if (WEXITSTATUS(child_state) == 252)
		g_exit_status = 0;
}

void	execute_parent(void)
{
	pid_t	rc_pid;
	int		child_state;

	rc_pid = 0;
	while (rc_pid != -1)
	{
		rc_pid = wait(&child_state);
		if (rc_pid == -1)
			break ;
		else if (rc_pid > 0)
		{
			if (WIFEXITED(child_state))
				set_child_exit_status(child_state);
			if (WIFSIGNALED(child_state))
				set_child_signaled_status(child_state);
		}
	}
}
