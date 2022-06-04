/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:03:37 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/20 12:27:16 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"
#include "../header/builtins.h"

void	update_env_pwd(t_data *data)
{
	t_env	*node;
	char	*pwd;

	node = get_keymatch_env_node(data->env_head, "PWD");
	if (node)
	{
		pwd = getcwd(NULL, 0);
		free(node->value);
		node->value = pwd;
		if (!node->equal_sign)
			node->equal_sign = true;
	}
}
