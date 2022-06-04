/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:56:43 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 10:51:26 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "utils.h"
# include "structs.h"
# include "exit.h"

enum e_builtin_code
{
	NO_BUILTIN,
	ECHO_BUILTIN,
	CD_BUILTIN,
	PWD_BUILTIN,
	EXPORT_BUILTIN,
	UNSET_BUILTIN,
	ENV_BUILTIN,
	EXIT_BUILTIN
};

/*	BUILTIN MAIN */
void	execute_builtin(t_data *data, char **argv);
int		check_builtin(t_data *data, char *cmd);

/*	BUILTIN FUNCTIONS */
void	echo(char **argv);
void	cd(t_data *data, char **argv);
void	pwd(void);
void	export(t_data *data, char **argv);
void	unset(t_env **head, char **argv);
void	env(t_data *data, char **argv);

#endif