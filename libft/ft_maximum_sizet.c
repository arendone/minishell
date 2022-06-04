/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maximum_sizet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:57:36 by marvin            #+#    #+#             */
/*   Updated: 2021/11/05 11:26:16 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_maximum_sizet(size_t n, ...)
{
	size_t	i;
	size_t	val;
	size_t	largest;
	va_list	vl;

	va_start (vl, n);
	largest = va_arg(vl, size_t);
	i = 1;
	while (i < n)
	{
		val = va_arg(vl, size_t);
		if (largest < val)
			largest = val;
		i++;
	}
	va_end(vl);
	return (largest);
}
