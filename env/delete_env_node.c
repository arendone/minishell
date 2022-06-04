/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_env_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:39:41 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/11 20:33:05 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

void	delete_env_node(t_env **head, t_env *node)
{
	if (node->prev == NULL && node->next == NULL)
	{	
		free_env_node(*head);
		*head = NULL;
		return ;
	}
	if (node->prev == NULL)
	{
		*head = node->next;
		(*head)->prev = NULL;
	}
	else if (node->next == NULL)
	{
		node->prev->next = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free_env_node(node);
}
