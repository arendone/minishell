/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:42:55 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 10:48:29 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtins.h"

void	execute_builtin(t_data *data, char **argv)
{
	int	builtin;

	builtin = data->builtin_code;
	if (builtin == ECHO_BUILTIN)
		echo(argv);
	else if (builtin == CD_BUILTIN)
		cd(data, argv);
	else if (builtin == PWD_BUILTIN)
		pwd();
	else if (builtin == EXPORT_BUILTIN)
		export(data, argv);
	else if (builtin == UNSET_BUILTIN)
		unset(&data->env_head, argv);
	else if (builtin == ENV_BUILTIN)
		env(data, argv);
	else if (builtin == EXIT_BUILTIN)
	{
		printf("exit\n");
		exit(0);
	}
}

int	check_builtin(t_data *data, char *cmd)
{
	int	builtin;

	if (is_equal_string_with_letter_casing(cmd, "echo"))
		builtin = ECHO_BUILTIN;
	else if (is_equal_string(cmd, "cd"))
		builtin = CD_BUILTIN;
	else if (is_equal_string_with_letter_casing(cmd, "pwd"))
		builtin = PWD_BUILTIN;
	else if (is_equal_string(cmd, "export"))
		builtin = EXPORT_BUILTIN;
	else if (is_equal_string(cmd, "unset"))
		builtin = UNSET_BUILTIN;
	else if (is_equal_string_with_letter_casing(cmd, "env"))
		builtin = ENV_BUILTIN;
	else if (is_equal_string(cmd, "exit"))
		builtin = EXIT_BUILTIN;
	else
		builtin = NO_BUILTIN;
	data->builtin_code = builtin;
	return (builtin);
}
