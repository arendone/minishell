/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:05:03 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/10 18:04:22 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

void	free_env_list(t_env *head)
{
	t_env	*node;
	t_env	*tmp;

	node = head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free_env_node(tmp);
	}
}
