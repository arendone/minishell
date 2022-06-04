/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:25:26 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/05 14:30:15 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*funcion no segura para el split, posible mal manejo con strchr*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while ((ft_strchr(set, (int)s1[start]) != NULL) && (start <= end))
		start++;
	if (start >= end)
		return (ft_strdup(""));
	while ((ft_strchr(set, (int)s1[end]) != NULL) && (end > 0))
		end--;
	trim = ft_substr(s1, start, (end + 1 - start));
	if (!trim)
		return (NULL);
	return (trim);
}
