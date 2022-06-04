/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:06:19 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/05 14:00:44 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The difference is that const char * is a pointer
to a const char , while char * const is a constant
pointer to a char . The first, the value being
pointed to can't be changed but the pointer can be.
The second, the value being pointed at can change
but the pointer can't*/

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cs;

	cs = (char *)s;
	i = 0;
	while (cs[i] != (char)c)
	{
		if (cs[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return (&cs[i]);
}
