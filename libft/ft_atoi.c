/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:53:38 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/06 14:04:01 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == '\n'
			|| c == ' '))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		n;
	int		i;
	int		sign;

	n = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (sign * n);
}
