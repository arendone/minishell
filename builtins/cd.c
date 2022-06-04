/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:17:01 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/20 12:29:20 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtins.h"
#include "../header/env.h"

void	cd(t_data *data, char **argv)
{
	char	*path;

	if (!argv[1])
	{
		path = get_keymatch_value(data->env_head, "HOME");
		if (!path)
		{
			error_exit("cd", "HOME not set");
			g_exit_status = 1;
		}
	}
	else
	{
		path = argv[1];
		update_env_oldpwd(data);
		if (chdir(path) != 0)
		{
			error_exit_three("cd", argv[1], "No such file or directory", 1);
			g_exit_status = 1;
		}
		else
			update_env_pwd(data);
	}
}
