/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keymatch_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:54:04 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/12 18:02:59 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"
#include "../header/builtins.h"

char	*get_keymatch_value(t_env *head, char *key)
{
	t_env	*node;

	node = head;
	while (node)
	{
		if (is_equal_string(node->key, key))
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
