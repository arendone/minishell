/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:38:16 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/23 15:30:15 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "utils.h"

# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

/*	SIGNAL FUNCTIONS */
void	signalhandler_ctrlc(int sig);
void	signal_child_ctrlc(int sig);
void	signals_setter(void);
void	signals_unsetter(void);
void	sig_child(int sig);
void	signal_ctrlc_hd(int sig);

#endif