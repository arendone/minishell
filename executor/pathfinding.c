/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:58:26 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/19 16:59:55 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

static void	free_env_paths(char **env_paths)
{
	int	i;

	i = 0;
	while (env_paths[i])
	{
		free(env_paths[i]);
		i++;
	}
	free(env_paths);
}

static char	*get_exec_path(char **env_paths, char *cmd)
{
	int		i;
	char	*exec_path;

	i = 0;
	while (env_paths[i])
	{
		exec_path = ft_strjoin(env_paths[i], cmd);
		if (access(exec_path, F_OK | X_OK) == 0)
			break ;
		free(exec_path);
		exec_path = NULL;
		i++;
	}
	return (exec_path);
}

static char	*append_slash_to_path(char *path)
{
	char	*path_with_slash;

	path_with_slash = ft_strjoin(path, "/");
	if (!path_with_slash)
		return (NULL);
	return (path_with_slash);
}

static char	**get_env_paths(t_env *head)
{
	char	*env_path_value;
	char	**env_paths;
	char	*tmp;
	int		i;

	env_path_value = get_keymatch_value(head, "PATH");
	if (!env_path_value)
		return (NULL);
	env_paths = ft_split(env_path_value, ':');
	if (!env_paths)
		return (NULL);
	i = 0;
	while (env_paths[i])
	{
		tmp = env_paths[i];
		env_paths[i] = append_slash_to_path(env_paths[i]);
		free(tmp);
		i++;
	}
	return (env_paths);
}

char	*get_path(t_env *head, char *cmd)
{
	char	**env_paths;
	char	*exec_path;

	if (access(cmd, F_OK | X_OK) == 0)
	{
		exec_path = ft_strdup(cmd);
		return (exec_path);
	}
	env_paths = get_env_paths(head);
	if (!env_paths)
		return (NULL);
	exec_path = get_exec_path(env_paths, cmd);
	free_env_paths(env_paths);
	return (exec_path);
}
