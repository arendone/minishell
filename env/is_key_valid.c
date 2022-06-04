/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:55:32 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/20 23:10:31 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

static bool	are_keychars_valid(char *key)
{
	int		i;
	bool	valid;

	i = 0;
	while (key[i] != '\0')
	{
		if ('a' <= key[i] && key[i] <= 'z')
			valid = true;
		else if ('A' <= key[i] && key[i] <= 'Z')
			valid = true;
		else if ('0' <= key[i] && key[i] <= '9')
			valid = true;
		else if (key[i] == '_')
			valid = true;
		else
			valid = false;
		if (!valid)
			break ;
		i++;
	}
	return (valid);
}

bool	is_key_valid(char *key)
{
	if (ft_strlen(key) == 0)
	{
		error_exit_three("export", "$", "not a valid identifier", 1);
		return (false);
	}
	else if ('0' <= key[0] && key[0] <= '9')
	{
		error_exit_three("export", key, "not a valid identifier", 1);
		return (false);
	}
	else if (!are_keychars_valid(key))
	{
		error_exit_three("export", key, "not a valid identifier", 1);
		return (false);
	}
	return (true);
}
