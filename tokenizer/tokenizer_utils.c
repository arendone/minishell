/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:38:08 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/20 20:42:38 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tokenizer.h"

bool	ft_isspace(char c)
{
	if ((c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == '\n'
			|| c == ' '))
		return (true);
	return (false);
}

int	check_status(int flag, int charac, int quote)
{
	if (quote == 0 && charac == '\'')
		quote = '\'';
	else if (quote == 0 && charac == '\"')
		quote = '\"';
	if (charac == quote)
		flag++;
	return (flag % 2);
}

int	calculator_status(t_state status, char c)
{
	if (status == STATE_GEN && c == '\'')
		status = STATE_IN_QUOTE;
	else if (status == STATE_GEN && c == '\"')
		status = STATE_IN_DQUOTE;
	else if (status == STATE_IN_QUOTE && c == '\'')
		status = STATE_GEN;
	else if (status == STATE_IN_DQUOTE && c == '\"')
		status = STATE_GEN;
	return (status);
}

int	quote_token(char *source)
{
	int		i;

	i = 0;
	while (source[i])
	{
		if (source[i] == '\'')
			return (STATE_IN_QUOTE);
		if (source[i] == '\"')
			return (STATE_IN_DQUOTE);
		if (source[i] == '$')
			return (STATE_DOLLAR);
		i++;
	}
	return (STATE_GEN);
}

int	count_dollars(char *str)
{
	int	i;
	int	count;

	if (str == NULL)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == '$')
			{
				i++;
			}
			count++;
		}
		i++;
	}
	return (count);
}
