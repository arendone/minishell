/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_list_sorted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:43:18 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/19 16:21:15 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"
#include "../header/builtins.h"

static void	compare_char(t_env *node, t_env **min, int i, int *remaining)
{
	int	cmp;

	cmp = ft_strncmp(node->key, (*min)->key, i);
	if (cmp == 1)
		node->sorting_value = CHECKED;
	else if (cmp == -1)
	{
		(*min)->sorting_value = CHECKED;
		*min = node;
	}
	else if (cmp == 0)
	{
		node->sorting_value = EQUAL;
		*remaining += 1;
	}
}

static t_env	*get_minimum_node(t_env *head, t_env *min, int i)
{
	t_env	*node;
	int		remaining;

	node = head;
	remaining = 0;
	while (node)
	{
		if (node->sorting_value == CHECKED)
		{
			node = node->next;
			continue ;
		}
		if (is_equal_string(node->key, min->key))
		{
			node = node->next;
			continue ;
		}
		compare_char(node, &min, i, &remaining);
		node = node->next;
	}
	if (remaining == 0)
		return (min);
	min = get_minimum_node(head, min, i + 1);
	return (min);
}

static void	set_sorting_value_to_default(t_env *head)
{
	t_env	*node;

	node = head;
	while (node)
	{
		node->sorting_value = DEFAULT;
		node = node->next;
	}
}

void	print_env_list_sorted(t_env *head)
{
	t_env	*head_copy;
	t_env	*node;

	head_copy = copy_env_list(head);
	delete_env_node(&head_copy, get_keymatch_env_node(head_copy, "_"));
	while (head_copy)
	{
		set_sorting_value_to_default(head_copy);
		node = get_minimum_node(head_copy, head_copy, 1);
		if (node->equal_sign)
			printf("%s=\"%s\"\n", node->key, node->value);
		else
			printf("%s=\n", node->key);
		delete_env_node(&head_copy, node);
	}
}
