/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_cmd_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:44:43 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 10:51:01 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"
#include "../header/builtins.h"

void	update_env_cmd_path(t_data *data, char *path)
{
	t_env	*node;

	node = get_keymatch_env_node(data->env_head, "_");
	if (node)
	{
		if (data->builtin_code)
		{
			free(node->value);
			node->value = ft_strdup("/minishell/builtins/builtin");
		}
		else if (path)
		{
			free(node->value);
			node->value = ft_strdup(path);
		}
	}
}
