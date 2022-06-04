/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:39:34 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/10 20:30:45 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

void	print_env_array(char **env_array)
{
	int	i;

	i = 0;
	while (env_array[i])
	{
		printf("%s\n", env_array[i]);
		i++;
	}
}
