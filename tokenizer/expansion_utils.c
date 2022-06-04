/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:42:08 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/20 20:33:55 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tokenizer.h"
#include "../header/env.h"

char	*get_expanded_variable(t_env *head, char *str, int i, char *var)
{
	char	*expanded_var;

	expanded_var = NULL;
	if (str[i - 1] == '$' && str[i] == '?')
		expanded_var = ft_itoa(g_exit_status);
	else if (str[i - 1] == '$' && str[i] == '$')
		expanded_var = ft_itoa((int)getpid());
	else
		expanded_var = ft_strdup(get_keymatch_value(head, var));
	return (expanded_var);
}

char	*get_variable(char *str)
{
	char	*var;
	int		i;

	i = 0;
	var = ft_calloc(ft_strlen(str) + 1, 1);
	if (ft_isalpha(str[0]) == 0 && (str[0] != '_'))
		return (var);
	while (str[i])
	{
		var[i] = str[i];
		i++;
	}
	return (var);
}

t_expansion	*get_expansion_strings(char *str, int i, int j)
{
	t_expansion	*strings;
	char		*tmp;

	strings = malloc(sizeof(t_expansion));
	if (!strings)
		return (NULL);
	strings->first = ft_substr(str, 0, i - 1);
	tmp = ft_substr(str, i, j);
	strings->var = get_variable(tmp);
	free(tmp);
	strings->last = ft_substr(str, i + j, ft_strlen(str) - (i + j));
	return (strings);
}

int	get_variable_end(char *str)
{
	int	j;

	j = 0;
	if ((ft_isalpha(str[j]) == 0) && (str[j] != '_'))
		return (1);
	while (str[j])
	{
		if ((ft_isalnum(str[j]) == 0) && (str[j] != '_'))
			break ;
		j++;
	}
	return (j);
}
