/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:43:48 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/10 17:47:15 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

void	copy_env_node(t_env *copy, t_env *node)
{
	copy->key = ft_strdup(node->key);
	copy->value = ft_strdup(node->value);
	copy->equal_sign = node->equal_sign;
}
