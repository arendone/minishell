/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:29:49 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/23 12:17:58 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

t_program	*create_program(t_token *tok_head)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (!program)
		return (NULL);
	program->tok_head = tok_head;
	program->n_tokens = 0;
	program->pid = -1;
	program->cmd_argv = NULL;
	program->nargvs = 0;
	program->fd[0] = 0;
	program->fd[1] = 1;
	program->redir_head = NULL;
	program->next = NULL;
	return (program);
}

t_program	*append_program(t_program *pro_head, t_token *tok_head)
{
	t_program	*current;

	current = pro_head;
	while (current->next)
	{
		current = current->next;
	}
	(current->next) = create_program(tok_head);
	return (current->next);
}

void	free_program_list(t_program	*pro_head)
{
	t_program	*current;
	t_program	*next;

	current = pro_head;
	while (current != NULL)
	{
		next = current->next;
		if (current->tok_head)
			free_token_list(current->tok_head);
		if (current->redir_head)
			free_redirection_list(current->redir_head);
		free(current->cmd_argv);
		free(current);
		current = next;
	}
}
