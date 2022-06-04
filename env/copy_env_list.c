/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:47:31 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/19 16:27:57 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

t_env	*copy_env_list(t_env *head)
{
	t_env	*head_copy;
	t_env	*copy;
	t_env	*node;

	head_copy = create_env_node();
	if (!head_copy)
		return (NULL);
	copy = head_copy;
	node = head;
	while (node)
	{
		copy_env_node(copy, node);
		if (node->next)
		{
			copy->next = create_env_node();
			if (!copy->next)
				break ;
			copy->next->prev = copy;
			copy = copy->next;
		}
		node = node->next;
	}
	return (head_copy);
}
