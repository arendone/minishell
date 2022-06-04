/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirection_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:05:04 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 12:09:22 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

static void	set_redirection_in(t_redir *dir, char *content, int len)
{
	if (len == 1)
		dir->type = REDIRECTION_LEFT;
	else if (len == 2 && content[1] == '<')
		dir->type = HEREDOC;
	else if (len == 2 && content[1] == '>')
		dir->type = REDIRECTION_LEFT;
	else
		dir->type = ERROR;
}

static void	set_redirection_out(t_redir *dir, char *content, int len)
{
	if (len == 1)
		dir->type = REDIRECTION_RIGHT;
	else if (len == 2 && content[1] == '|')
		dir->type = REDIRECTION_RIGHT;
	else if (len == 2 && content[1] == '>')
		dir->type = DOUBLE_REDIRECTION;
	else
		dir->type = ERROR;
}

void	set_redirection_type(t_redir *dir, char *content)
{
	int	len;

	len = ft_strlen(content);
	if (len > 2)
		dir->type = ERROR;
	else if (content[0] == '>')
		set_redirection_out(dir, content, len);
	else if (content[0] == '<')
		set_redirection_in(dir, content, len);
}
