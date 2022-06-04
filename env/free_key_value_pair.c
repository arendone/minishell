/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_key_value_pair.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:36:02 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/10 20:39:15 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

void	free_key_value_pair(char **key_value_pair)
{
	int	i;

	i = 0;
	while (key_value_pair[i])
	{
		free(key_value_pair[i]);
		i++;
	}
	free(key_value_pair);
}
