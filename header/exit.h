/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:08:41 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/24 15:26:59 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "utils.h"

# define EXIT_SUCCESS 0
# define EXIT_MALLOC_FAILURE -1
# define EXIT_PIPE_FAILURE -2
# define EXIT_DUP_FAILURE -3
# define EXIT_READLINE_FAILURE -4

extern int	g_exit_status;

/*	ERROR FUNCTIONS */
void	error_exit(char *arg, char *msg);
void	error_exit_specified(char *arg1, char *arg2, char *msg, int code);
void	error_exit_three(char *arg1, char *arg2, char *msg, int code);
void	error_unexpectedtoken(char *token, int code);
int		exit_set_error(char *path, char *cmd);

#endif