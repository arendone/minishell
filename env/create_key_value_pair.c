/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_key_value_pair.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:36:21 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/11 17:22:43 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

static void	parse_line(char *line, char **pair)
{
	int	i;

	i = 0;
	while (line[i] != '=' && line[i] != '\0')
		i++;
	if (line[i] == '=')
	{
		line[i] = '\0';
		pair[0] = ft_strdup(line);
		pair[1] = ft_strdup("=");
		pair[2] = ft_strdup(&line[i + 1]);
	}
	else
	{
		pair[0] = ft_strdup(line);
		pair[1] = NULL;
		pair[2] = NULL;
	}
	pair[3] = NULL;
}

char	**create_key_value_pair(char *line)
{
	char	**key_value_pair;
	char	*copy;

	if (!line)
		return (NULL);
	key_value_pair = malloc(4 * sizeof(char *));
	if (!key_value_pair)
		return (NULL);
	copy = ft_strdup(line);
	parse_line(copy, key_value_pair);
	free(copy);
	return (key_value_pair);
}
