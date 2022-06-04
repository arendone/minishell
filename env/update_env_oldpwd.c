/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_oldpwd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:03:37 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/20 12:30:24 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"
#include "../header/builtins.h"

void	update_env_oldpwd(t_data *data)
{
	t_env	*node;
	char	*oldpwd;

	node = get_keymatch_env_node(data->env_head, "OLDPWD");
	if (node)
	{
		oldpwd = getcwd(NULL, 0);
		free(node->value);
		node->value = oldpwd;
		if (!node->equal_sign)
			node->equal_sign = true;
	}
}
