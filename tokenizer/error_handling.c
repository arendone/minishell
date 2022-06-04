/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:03:35 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/25 17:57:58 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tokenizer.h"

int	unclosed_quotes(char *str)
{
	t_state	state;
	int		i;

	i = 0;
	state = STATE_GEN;
	while (str[i])
	{
		if (str[i] == '\'' && state == STATE_GEN)
			state = STATE_IN_QUOTE;
		else if (str[i] == '\"' && state == STATE_GEN)
			state = STATE_IN_DQUOTE;
		else if (str[i] == '\'' && state == STATE_IN_QUOTE)
			state = STATE_GEN;
		else if (str[i] == '\"' && state == STATE_IN_DQUOTE)
			state = STATE_GEN;
		i++;
	}
	return (state);
}

int	wrong_input(char *str)
{
	if (unclosed_quotes(str) != 0)
		return (1);
	else
		return (0);
}
