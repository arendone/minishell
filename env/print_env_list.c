/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:39:33 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/11 12:45:06 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

void	print_env_list(t_env *head)
{
	t_env	*node;

	node = head;
	while (node)
	{
		if (node->key && node->equal_sign && node->value)
			printf("%s=%s\n", node->key, node->value);
		node = node->next;
	}
}
