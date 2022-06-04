/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:03:12 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/19 16:20:29 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

static void	create_env_list_elements(t_env **head, char **argv)
{
	int		i;
	t_env	*node;
	char	**key_value_pair;

	i = 0;
	node = *head;
	while (argv[i])
	{
		key_value_pair = create_key_value_pair(argv[i]);
		fill_env_node(node, key_value_pair);
		if (argv[i + 1])
		{
			node->next = create_env_node();
			if (!node->next)
				break ;
			node->next->prev = node;
			node = node->next;
		}
		free_key_value_pair(key_value_pair);
		i++;
	}
}

t_env	*create_env_list(char **argv)
{
	t_env	*head;

	head = create_env_node();
	if (!head)
		return (NULL);
	create_env_list_elements(&head, argv);
	return (head);
}
