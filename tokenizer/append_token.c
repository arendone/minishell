/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:16:07 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 13:06:59 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tokenizer.h"

t_token	*append_token(t_token *head)
{
	t_token	*current;
	t_token	*new;

	current = head;
	while (current->next)
	{
		current = current->next;
	}
	new = create_token();
	(current->next) = new;
	new->prev = current;
	return (new);
}
