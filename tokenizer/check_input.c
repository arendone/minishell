/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:05:41 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/23 14:03:10 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tokenizer.h"

int	empty_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == false)
			return (1);
		i++;
	}
	return (0);
}

int	double_operator(t_token *head)
{
	t_token	*current;
	t_token	*next;

	if (head->type == PIPE)
	{
		error_unexpectedtoken(head->content, 258);
		return (1);
	}
	current = head;
	while (current->next)
	{
		next = current->next;
		if (((current->type != WORD && current->type != PIPE)
				&& next->type != WORD)
			|| (current->type == PIPE && next->type == PIPE))
		{
			error_unexpectedtoken(next->content, 258);
			return (1);
		}
		current = next;
	}
	return (0);
}
