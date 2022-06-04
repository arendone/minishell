/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:40:47 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/10 20:41:19 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

void	fill_env_node(t_env *node, char **key_value_pair)
{
	if (key_value_pair[0])
		node->key = ft_strdup(key_value_pair[0]);
	if (key_value_pair[1])
		node->equal_sign = true;
	if (key_value_pair[2])
		node->value = ft_strdup(key_value_pair[2]);
}
