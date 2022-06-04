/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keymatch_env_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:02:03 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/12 18:02:06 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"
#include "../header/builtins.h"

t_env	*get_keymatch_env_node(t_env *head, char *key)
{
	t_env	*node;

	node = head;
	while (node)
	{
		if (is_equal_string(node->key, key))
			return (node);
		node = node->next;
	}
	return (NULL);
}
