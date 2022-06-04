/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:08:53 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/31 18:06:04 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* In the C Programming Language, the atof function converts a string to a 
floating-point number (double). The atof function skips all white-space 
characters at the beginning of the string, converts the subsequent characters 
as part of the number, and then stops when it encounters the first character 
that isn't a number. */

static int	ft_isspace(char c)
{
	if ((c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == '\n'
			|| c == ' '))
		return (1);
	return (0);
}

static double	get_number(char *str, int i)
{
	int			flag;
	long double	f;
	long double	count_dec;

	count_dec = 1.0;
	flag = 0;
	f = 0.0;
	while ((str[i] >= '0' && str[i] <= '9' && flag < 2) || str[i] == '.')
	{
		if (str[i] == '.')
			flag++;
		else if (flag == 0)
			f = f * 10.0 + (str[i] - '0');
		else if (flag == 1)
		{
			f = f * 10.0 + (str[i] - '0');
			count_dec = count_dec * 10.0;
		}
		i++;
	}
	return (f / count_dec);
}

double	ft_atof(char *str)
{
	int		i;
	double	sign;
	double	num;

	i = 0;
	sign = 1.0;
	while (ft_isspace(*str))
		str++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	num = get_number(str, i);
	return (sign * num);
}
