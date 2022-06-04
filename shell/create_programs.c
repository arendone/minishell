/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_programs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:56 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/23 12:13:30 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

t_program	*create_programs(t_token *tok_head, int n_pipes)
{
	t_program	*pro_head;
	t_program	*tmp_prog;
	t_token		*tmp_tok_head;

	pro_head = create_program(tok_head);
	tmp_tok_head = tok_head;
	while (n_pipes > 0)
	{
		tmp_tok_head = find_next_head_and_cut_pipe(tmp_tok_head);
		tmp_prog = append_program(pro_head, tmp_tok_head);
		n_pipes--;
	}
	return (pro_head);
}

/*return 0 on success and 1 if there is an error*/
void	fill_one_program(t_program *prog)
{
	t_token	*current;
	int		i;
	char	*content;

	fill_standard_input(prog);
	current = prog->tok_head;
	i = 0;
	while (i < prog->nargvs)
	{
		content = current->content;
		if ((content[0] == '<' || content[0] == '>') && (current->quote == 0))
		{
			current = call_redirection(prog, current);
			prog->nargvs = (prog->nargvs) - 2;
			i--;
		}
		else
		{
			prog->cmd_argv[i] = content;
			current = current->next;
		}
		i++;
	}
	prog->cmd_argv[i] = NULL;
}

void	fill_standard_input(t_program *prog)
{
	prog->n_tokens = count_tokens(prog->tok_head);
	prog->cmd_argv = malloc((prog->n_tokens + 1) * sizeof(char *));
	if (prog->cmd_argv == NULL)
		exit(EXIT_MALLOC_FAILURE);
	prog->nargvs = prog->n_tokens;
}

void	fill_all_programs(t_program *pro_head)
{
	t_program	*current;

	g_exit_status = 0;
	current = pro_head;
	while (current->next)
	{
		fill_one_program(current);
		current = current->next;
	}
	fill_one_program(current);
}
