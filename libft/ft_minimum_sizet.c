/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimum_sizet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:24:22 by marvin            #+#    #+#             */
/*   Updated: 2021/11/05 11:26:26 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_minimum_sizet(size_t n, ...)
{
	size_t	i;
	size_t	val;
	size_t	minimum;
	va_list	vl;

	va_start (vl, n);
	minimum = va_arg(vl, size_t);
	i = 1;
	while (i < n)
	{
		val = va_arg(vl, size_t);
		if (minimum > val)
			minimum = val;
		i++;
	}
	va_end(vl);
	return (minimum);
}
