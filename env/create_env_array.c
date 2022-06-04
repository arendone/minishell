/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:08:12 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/20 16:02:48 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

static char	*join_key_value_pair(char *key, char *value)
{
	int		length;
	char	*line;
	int		i;
	int		j;

	length = ft_strlen(key) + ft_strlen(value) + 1;
	line = malloc((length + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (key[i] != '\0')
	{
		line[i] = key[i];
		i++;
	}
	line[i] = '=';
	i++;
	j = 0;
	while (value[j] != '\0')
	{
		line[i + j] = value[j];
		j++;
	}
	line[i + j] = '\0';
	return (line);
}

static int	count_nodes(t_env *head)
{
	int		count;
	t_env	*node;

	count = 0;
	node = head;
	while (node)
	{
		if (node->equal_sign)
			count += 1;
		node = node->next;
	}
	return (count);
}

char	**create_env_array(t_env *head)
{
	int		count;
	char	**env_array;
	t_env	*node;
	int		i;

	count = count_nodes(head);
	env_array = malloc((count + 1) * sizeof(char *));
	if (!env_array)
		return (NULL);
	node = head;
	i = 0;
	while (node && i < count)
	{
		if (node->equal_sign)
		{
			env_array[i] = join_key_value_pair(node->key, node->value);
			i++;
		}
		node = node->next;
	}
	env_array[count] = NULL;
	return (env_array);
}
