/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equal_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:09:37 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/20 18:58:54 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

int	is_equal_string_with_letter_casing(const char *s1, const char *s2)
{
	int	i;
	int	len1;
	int	len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 == len2)
	{
		while (s1[i] != '\0')
		{
			if (s1[i] != s2[i] && s1[i] != s2[i] - 32)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	is_equal_string(const char *s1, const char *s2)
{
	int	i;
	int	len1;
	int	len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 == len2)
	{
		while (s1[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

char	*str_copy(char *str)
{
	char	*copy;
	int		i;
	int		len;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	copy = (char *)malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
