/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:38:28 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/20 20:42:59 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tokenizer.h"

void	fill_content(t_env *env_head, t_token *head)
{
	t_token	*current;
	char	*tmp;
	int		dollars;

	current = head;
	dollars = 0;
	while (current)
	{
		current->quote = quote_token(current->source);
		if (current->quote == STATE_DOLLAR || current->quote == STATE_IN_DQUOTE)
		{
			tmp = str_copy(current->source);
			dollars = count_dollars(tmp);
			while (dollars)
			{
				tmp = expansion(env_head, tmp);
				dollars--;
			}
			current->content = remove_quotes(tmp);
			free(tmp);
		}
		else
			current->content = remove_quotes(current->source);
		current = current->next;
	}
}

void	fill_type(t_token *head)
{
	t_token	*current;
	int		type;

	current = head;
	type = 0;
	while (current)
	{
		if (current->quote == STATE_GEN)
		{
			if (ft_strlen(current->content) == 1)
			{
				search_operator(current, 1);
			}
			else if (ft_strlen(current->content) == 2)
			{
				search_operator(current, 2);
			}
		}
		current = current->next;
	}
}

void	search_operator(t_token *current, int len)
{
	char	*content;

	content = current->content;
	if (len == 1)
	{
		if (content[0] == '<')
			current->type = REDIR_LESS;
		else if (content[0] == '>')
			current->type = REDIR_GREAT;
		else if (content[0] == '|')
			current->type = PIPE;
	}
	else if (len == 2)
	{
		if (content[0] == '<' && content[1] == '<')
			current->type = REDIR_DLESS;
		else if (content[0] == '>' && content[1] == '|')
			current->type = REDIR_GREAT;
		else if (content[0] == '>' && content[1] == '>')
			current->type = REDIR_DGREAT;
		else if (content[0] == '<' && content[1] == '>')
			current->type = REDIR_LESS;
	}
}

char	*remove_quotes(char *source)
{
	char	*content;
	int		len;
	int		i;
	t_state	status;

	if (!source)
		return (NULL);
	i = 0;
	len = 0;
	status = STATE_GEN;
	content = ft_calloc(ft_strlen(source)+ 1, 1);
	if (content == NULL)
		exit(EXIT_MALLOC_FAILURE);
	while (source[i])
	{
		status = calculator_status(status, source[i]);
		if (check_condition(status, source, i) == true)
		{
			content[len] = source[i];
			len++;
		}
		i++;
	}
	return (content);
}

int	check_condition(t_state status, char *source, int i)
{
	if ((source[i] != '\'' && status == STATE_IN_QUOTE)
		|| (source[i] != '\"' && status == STATE_IN_DQUOTE)
		|| (source[i] != '\'' && source[i] != '\"' && status == STATE_GEN))
		return (true);
	else
		return (false);
}
