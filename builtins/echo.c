/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:41:43 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/19 15:41:05 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtins.h"

static void	check_string(char *arg, bool *option_n, int *i)
{
	if (!arg)
	{
		*i = 1;
		*option_n = false;
	}
	else if (is_equal_string(arg, "-n"))
	{
		*i = 2;
		*option_n = true;
	}
	else
	{
		*i = 1;
		*option_n = false;
	}
}

void	echo(char **argv)
{
	bool	option_n;
	int		i;

	check_string(argv[1], &option_n, &i);
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	if (!option_n)
		printf("\n");
}
