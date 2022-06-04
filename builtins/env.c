/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:58:32 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/19 15:16:09 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtins.h"
#include "../header/env.h"

void	env(t_data *data, char **argv)
{
	if (argv[1] != NULL)
	{
		if (argv[1][0] == '-')
		{
			if (argv[1][1] != '\0')
				error_exit_specified("env", "illegal option", argv[1], 1);
		}
		else
		{
			error_exit(argv[1], "No such file or directory");
			g_exit_status = 127;
		}
	}
	else
		print_env_list(data->env_head);
}
