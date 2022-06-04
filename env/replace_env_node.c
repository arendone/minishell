/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:39:25 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/12 15:33:48 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

void	replace_env_node(t_env *head, char **key_value_pair)
{
	t_env	*node;

	node = get_keymatch_env_node(head, key_value_pair[0]);
	free(node->value);
	node->value = ft_strdup(key_value_pair[2]);
	if (key_value_pair[1])
		node->equal_sign = true;
	else
		node->equal_sign = false;
}
