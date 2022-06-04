/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:30:01 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/05 14:28:47 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(const char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i] != '\0' && s[i] == c)
	{
		i++;
	}
	if (s[i] != '\0')
		words = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if ((s[i + 1] != '\0') && (s[i + 1] != c))
				words++;
		}
		i++;
	}
	return (words);
}

static char	**clean(char **split, int n)
{
	while (n >= 0)
	{
		free (split[n - 1]);
		n--;
	}
	free(split);
	split = NULL;
	return (NULL);
}

static char	*ft_mallocstr(char *ptr, char delim)
{
	int		i;
	char	*strptr;

	i = 0;
	while (ptr[i] != delim && ptr[i] != '\0')
		i++;
	strptr = (char *) malloc((i + 1) * sizeof(char));
	if (strptr == NULL)
		return (NULL);
	ft_strlcpy(strptr, ptr, i + 1);
	return (strptr);
}

static char	**write_to_arr(char const *str, char **arr, char c)
{
	int	i;
	int	k;
	int	flag;

	k = 0;
	i = 0;
	flag = 1;
	while (str[i])
	{
		if (str[i] == c)
			flag = 1;
		if ((str[i] != c) && (flag == 1))
		{
			arr[k] = (char *) ft_mallocstr(&((char *)str)[i], c);
			if (arr[k] == NULL)
			{
				clean(arr, k);
				return (NULL);
			}
			k++;
			flag = 0;
		}
		i++;
	}
	return (arr);
}

char	**ft_split(char const *str, char c)
{
	int		wordcount;
	char	**arr;

	if (str == NULL)
		return (NULL);
	wordcount = countwords(str, c);
	arr = malloc((wordcount + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr[wordcount] = NULL;
	arr = write_to_arr(str, arr, c);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
