/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:59:03 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/23 15:59:08 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/signals.h"
#include "../header/exit.h"

void	signalhandler_ctrlc(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signals_setter(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &term);
	signal(SIGINT, signalhandler_ctrlc);
	signal(SIGQUIT, SIG_IGN);
}

void	signals_unsetter(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(1, 0, &term);
	signal(SIGINT, SIG_IGN);
}

void	sig_child(int sig)
{
	if (sig == SIGINT)
		exit(2);
	if (sig == SIGQUIT)
		exit(3);
}

void	signal_ctrlc_hd(int sig)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &term);
	if (sig == SIGINT)
	{
		ft_printf("♥   \n");
		close(STDIN_FILENO);
		g_exit_status = 1;
	}
}
