/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:52:34 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/20 22:35:10 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tokenizer.h"
#include "../header/env.h"

void	free_expansion_memory(t_expansion *strings, char *var, char *str)
{
	free(strings->first);
	free(strings->var);
	free(strings->last);
	free(strings);
	free(var);
	free(str);
}

char	*join_strings(char *first, char *second, char *third)
{
	char	*joined;
	int		len_first;
	int		len_second;
	int		len_third;

	len_first = ft_strlen(first);
	len_second = ft_strlen(second);
	len_third = ft_strlen(third);
	joined = ft_calloc(len_first + len_second + len_third + 1, 1);
	ft_strlcpy(joined, first, len_first + 1);
	ft_strlcpy((joined + len_first), second, len_second + 1);
	ft_strlcpy((joined + len_first + len_second), third, len_third + 1);
	return (joined);
}

char	*get_expanded_string(t_env *head, char *str, int i)
{
	int			variable_end;
	t_expansion	*strings;
	char		*expanded_var;
	char		*expanded_str;

	variable_end = get_variable_end(str + i);
	strings = get_expansion_strings(str, i, variable_end);
	expanded_var = get_expanded_variable(head, str, i, strings->var);
	expanded_str = join_strings(strings->first, expanded_var, strings->last);
	free_expansion_memory(strings, expanded_var, str);
	return (expanded_str);
}

char	*expansion(t_env *head, char *str)
{
	int		i;
	char	*expanded_str;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == ' ' || str[i] == '\0')
			{
				i++;
				continue ;
			}
			expanded_str = get_expanded_string(head, str, i + 1);
			return (expanded_str);
		}
		i++;
	}
	return (str);
}
