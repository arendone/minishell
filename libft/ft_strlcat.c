/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:45:26 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/01 15:08:35 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*csrc;
	size_t	len_dst;
	size_t	counter;

	csrc = (char *)src;
	len_dst = ft_strlen(dst);
	if (dstsize != 0)
	{
		counter = 0;
		while ((len_dst + counter < dstsize - 1) && csrc[counter] != '\0')
		{
			dst[len_dst + counter] = csrc[counter];
			counter++;
		}
		if (len_dst + counter < dstsize)
			dst[len_dst + counter] = '\0';
	}
	if (dstsize > len_dst)
		return (len_dst + ft_strlen(src));
	return (dstsize + ft_strlen(src));
}
