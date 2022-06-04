/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:32:25 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 14:53:42 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

int	count_tokens(t_token *tok_head)
{
	t_token	*current;
	int		count;

	current = tok_head;
	if (current->content)
		count = 1;
	else
		count = 0;
	while (current->next != NULL)
	{
		current = current->next;
		count += 1;
	}
	return (count);
}

/* It goes into the list of token until | && unquoted, 
	cut the list(point it to NULL) and keep
	the new head in the tmp_tok_head */
t_token	*find_next_head(t_token *tok_head)
{
	t_token	*tmp_tok_head;
	t_token	*current;
	char	*content;

	current = tok_head;
	content = current->content;
	while (!(content[0] == '|' && current->quote == 0))
	{
		current = (current->next);
		content = current->content;
	}
	tmp_tok_head = (current->next);
	current->next = NULL;
	return (tmp_tok_head);
}

void	cut_pipe(t_token *head)
{
	t_token	*current;
	t_token	*last;

	current = head;
	last = current->next;
	while (last->next)
	{
		current = last;
		last = current->next;
	}
	current->next = NULL;
	free(last->source);
	free(last->content);
	free(last);
	last = NULL;
}

/*remove pipe from last list*/
t_token	*find_next_head_and_cut_pipe(t_token *tok_head)
{
	t_token	*tmp_tok_head;
	t_token	*current;
	char	*content;

	current = tok_head;
	content = current->content;
	while (!(content[0] == '|' && current->quote == 0))
	{
		current = (current->next);
		content = current->content;
	}
	tmp_tok_head = (current->next);
	current->next = NULL;
	cut_pipe(tok_head);
	return (tmp_tok_head);
}
