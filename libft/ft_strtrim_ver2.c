/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_ver2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:05:30 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/05 14:08:40 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_ver2(char const *s1, char c)
{
	char	*trim;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while ((s1[start] == c) && (start <= end))
		start++;
	if (start >= end)
		return (ft_strdup(""));
	while ((s1[end] == c) && (end > 0))
		end--;
	trim = ft_substr(s1, start, (end + 1 - start));
	if (!trim)
		return (NULL);
	return (trim);
}
