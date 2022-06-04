/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:57:56 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/19 14:52:29 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtins.h"
#include "../header/env.h"

void	unset(t_env **head, char **argv)
{
	int		i;
	t_env	*node;

	i = 1;
	while (argv[i])
	{
		node = get_keymatch_env_node(*head, argv[i]);
		if (node && node->key[0] != '_' && node->key[1] != '\0')
			delete_env_node(head, node);
		i++;
	}
}
