/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:15:10 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/23 11:58:59 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*cs;

	cs = (char *)s;
	len = ft_strlen(cs);
	while (len >= 0)
	{
		if (cs[len] == (c % 256))
			return (&cs[len]);
		len--;
	}
	return (NULL);
}
