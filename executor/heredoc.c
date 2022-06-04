/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:02:31 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/24 15:16:57 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/executor.h"
#include "../header/tokenizer.h"

static char	*expand_line(t_data *data, char *line)
{
	int	dollars;

	dollars = count_dollars(line);
	while (dollars)
	{
		line = expansion(data->env_head, line);
		dollars--;
	}
	return (line);
}

static int	check_line(char *line, char *delimiter)
{
	if (!line)
	{
		free(delimiter);
		return (1);
	}
	if (is_equal_string(delimiter, line))
	{
		free(line);
		free(delimiter);
		return (1);
	}
	return (0);
}

static char	*get_delimiter(t_redir *current, int *quote)
{
	char	*delimiter;

	delimiter = remove_quotes(current->file);
	if (is_equal_string(delimiter, current->file) == 0)
		*quote = STATE_IN_QUOTE;
	return (delimiter);
}

static int	write_in_heredoc(t_data *data, t_redir *current, int fd_heredoc)
{
	int		quote;
	char	*line;
	char	*delimiter;
	int		len;

	quote = STATE_GEN;
	line = NULL;
	delimiter = get_delimiter(current, &quote);
	line = readline("♥ ");
	if (check_line(line, delimiter) == 1)
		return (1);
	if (quote == STATE_GEN)
		line = expand_line(data, line);
	len = ft_strlen(line);
	write(fd_heredoc, line, len);
	write(fd_heredoc, "\n", 1);
	free(line);
	free(delimiter);
	return (0);
}

int	heredoc(t_data *data, t_program *program, t_redir *current)
{
	t_token	*head;

	if (pipe(program->fd) == -1)
		return (-1);
	{
		head = program->tok_head;
		signal(SIGINT, signal_ctrlc_hd);
		while (1)
		{
			if (g_exit_status != 0)
			{
				signals_unsetter();
				return (0);
			}
			if (write_in_heredoc(data, current, program->fd[1]) == 1)
				break ;
		}
	}
	close(program->fd[1]);
	dup2(program->fd[0], STDIN_FILENO);
	close(program->fd[0]);
	return (0);
}
