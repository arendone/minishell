/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:23:18 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/10 16:01:52 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	if (!s1)
		return (NULL);
	copy = (char *)malloc(ft_strlen(s1) + 1);
	if (copy == NULL)
		return (NULL);
	else
		ft_strlcpy(copy, s1, ft_strlen(s1) + 1);
	return (copy);
}
