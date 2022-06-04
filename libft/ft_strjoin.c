/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:34:25 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/16 15:19:54 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	else
	{
		join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (join == NULL)
			return (NULL);
		ft_strlcpy(join, s1, ft_strlen(s1) + 1);
		ft_strlcpy(&join[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	}	
	return (join);
}
