/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:32:54 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/12 18:02:00 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"
#include "../header/builtins.h"

t_env	*get_last_env_node(t_env *head)
{
	t_env	*node;

	node = head;
	while (node->next)
		node = node->next;
	return (node);
}
