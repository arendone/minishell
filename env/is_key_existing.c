/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_existing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:54:59 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/10 21:09:52 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

bool	is_key_existing(t_env *head, char *key)
{
	t_env	*node;

	node = get_keymatch_env_node(head, key);
	if (node)
		return (true);
	return (false);
}
