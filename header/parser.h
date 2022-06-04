/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:46:36 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 12:50:57 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "utils.h"
# include "structs.h"
# include "exit.h"
# include "tokenizer.h"

/*	CREATE PROGRAMS */
t_program	*create_program(t_token *tok_head);
void		fill_standard_input(t_program *prog);
t_program	*append_program(t_program *pro_head, t_token *tok_head);
void		free_program_list(t_program	*pro_head);

/*	FILL PROGRAMS */
t_program	*create_programs(t_token *tok_head, int n_pipes);
void		fill_one_program(t_program *prog);
void		fill_all_programs(t_program *pro_head);

/*	PARSER UTILITY FUNCTIONS */
int			count_tokens(t_token *tok_head);
t_token		*find_next_head(t_token *tok_head);
t_token		*find_next_head_and_cut_pipe(t_token *tok_head);
void		cut_pipe(t_token *head);

/*	CREATE REDIRECTIONS */
t_redir		*create_redirection(void);
t_redir		*append_redirection(t_redir *re_head);
void		free_redirection_list(t_redir *re_head);

/*	SET REDIRECTION TYPES */
t_token		*call_redirection(t_program *prog, t_token *token);
void		set_redirection_type(t_redir *dir, char *content);

/*	PRINT REDIRECTIONS */
void		print_redir(t_program *pro_head);

#endif