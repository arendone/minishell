/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:59:12 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/23 12:18:18 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

void	free_redirection_list(t_redir *re_head)
{
	t_redir	*current;
	t_redir	*next;

	current = re_head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

t_redir	*append_redirection(t_redir *re_head)
{
	t_redir	*current;

	current = re_head;
	while (current->next)
	{
		current = current->next;
	}
	(current->next) = create_redirection();
	return (current->next);
}

t_redir	*create_redirection(void)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = -1;
	redir->file = NULL;
	redir->mode = -1;
	redir->next = NULL;
	return (redir);
}
