/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:40:55 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/23 13:01:19 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

static int	check_redirection_errors(t_token *cur_token)
{
	if (cur_token == NULL)
	{
		error_unexpectedtoken("newline", 258);
		return (-1);
	}
	if (ft_strlen(cur_token->content) == 0)
	{
		error_exit_specified("minishell: ",
			cur_token->source, "ambiguous redirect", 1);
		return (-1);
	}
	return (0);
}

static t_redir	*start_redirection(t_program *prog)
{
	t_redir	*cur_redir;

	if (prog->redir_head == NULL)
	{
		prog->redir_head = create_redirection();
		cur_redir = prog->redir_head;
	}
	else
		cur_redir = append_redirection(prog->redir_head);
	return (cur_redir);
}

t_token	*call_redirection(t_program *prog, t_token *token)
{
	t_token	*cur_token;
	t_redir	*cur_redir;

	cur_redir = start_redirection(prog);
	cur_token = token;
	set_redirection_type(cur_redir, cur_token->content);
	cur_token = cur_token->next;
	if (check_redirection_errors(cur_token) == -1)
		return (NULL);
	if (cur_redir->type == HEREDOC)
		cur_redir->file = cur_token->source;
	else
		cur_redir->file = cur_token->content;
	cur_token = cur_token->next;
	if (cur_token == NULL)
		return (NULL);
	return (cur_token);
}
