/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:57:02 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/20 23:05:57 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtins.h"
#include "../header/env.h"

void	export(t_data *data, char **argv)
{
	int		i;
	char	**key_value_pair;

	i = 1;
	while (argv[i])
	{
		key_value_pair = create_key_value_pair(argv[i]);
		if (is_key_valid(key_value_pair[0]))
		{
			if (is_key_existing(data->env_head, key_value_pair[0]))
				replace_env_node(data->env_head, key_value_pair);
			else if (!data->env_head)
				data->env_head = create_env_list(argv);
			else
				add_env_node(data->env_head, key_value_pair);
		}
		free_key_value_pair(key_value_pair);
		i++;
	}
	if (argv[1] == NULL)
		print_env_list_sorted(data->env_head);
}
