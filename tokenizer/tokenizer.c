/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:22:37 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/18 15:00:34 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tokenizer.h"

char	*cut_word(char *start, int len)
{
	char	*content;
	int		i;

	if (!start)
		return (NULL);
	content = malloc((len + 1) * sizeof(char));
	if (!content)
		return (NULL);
	i = 0;
	while (i < len)
	{
		content[i] = start[i];
		i++;
	}
	content[i] = '\0';
	return (content);
}

static int	calculate_j(char *str, int j)
{
	int	len;

	len = ft_strlen(str + j);
	if (len == 1)
		return (1);
	else if (j > 0)
		return (j);
	else if (str[j] == '|')
		return (1);
	else if (str[j] == '>' && str[j + 1] == '|')
		return (2);
	else if (str[j] == '<' && str[j + 1] == '>')
		return (2);
	else if (str[j] != str[j + 1])
		return (1);
	else
		return (2);
}

int	len_of_j(char *start, int quote)
{
	int		j;
	t_state	flag;

	j = 0;
	flag = 0;
	while (start[j] != '\0')
	{
		flag = check_status(flag, start[j], quote);
		if ((ft_isspace(start[j]) == true) && flag == 0)
			break ;
		if ((start[j] == '>' || start[j] == '<' || start[j] == '|')
			&& flag == 0)
		{
			j = calculate_j(start, j);
			break ;
		}
		j++;
	}
	return (j);
}

int	search_word(t_token *head, char *start, int i, int quote)
{
	t_token	*token;
	int		j;

	j = len_of_j(start, quote);
	if (!head->next && !head->source)
		head->source = cut_word(start, j);
	else
	{
		token = append_token(head);
		token->source = cut_word(start, j);
	}
	return (i + j);
}

t_token	*tokenizer(t_env *env_head, char *line)
{
	t_token	*head;
	int		i;

	head = create_token();
	if (!head)
		return (NULL);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 34 || line[i] == 39)
			i = search_word(head, &line[i], i, line[i]);
		else if (ft_isspace(line[i]) == 1)
			i++;
		else
			i = search_word(head, &line[i], i, 0);
	}
	fill_content(env_head, head);
	fill_type(head);
	if (double_operator(head) == 1)
	{
		free_token_list(head);
		return (NULL);
	}
	return (head);
}
