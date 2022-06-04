/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:07:43 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 13:08:23 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "utils.h"
# include "structs.h"
# include "exit.h"

/*	CREATE TOKENS */
t_token		*create_token(void);
t_token		*append_token(t_token *head);
void		free_token_list(t_token	*head);

/*	FILL TOKENS */
char		*cut_word(char *start, int len);
int			len_of_j(char *start, int quote);
t_token		*tokenizer(t_env *env_head, char *line);
int			search_word(t_token *head, char *start, int i, int quote);

/* TOKENIZER UTILS */
bool		ft_isspace(char c);
int			check_status(int flag, int charac, int quote);
int			calculator_status(t_state status, char c);
int			quote_token(char *source);
int			count_dollars(char *str);

/*	CHECK INPUT */
int			empty_input(char *str);
int			double_operator(t_token *head);

/*	ERROR HANDLING */
int			unclosed_quotes(char *str);
int			not_required_chars(char *str);
int			wrong_input(char *str);

/*	QUOTE REMOVAL */
char		*remove_quotes(char *source);
void		fill_content(t_env *env_head, t_token *head);
void		fill_type(t_token *head);
void		search_operator(t_token *current, int len);
int			check_condition(t_state status, char *source, int i);

/*	VARIABLE EXPANSION */
char		*expansion(t_env *head, char *str);
int			get_variable_end(char *str);
char		*get_expanded_string(t_env *head, char *str, int i);
t_expansion	*get_expansion_strings(char *str, int i, int j);
char		*get_variable(char *str);
char		*get_expanded_variable(t_env *head, char *str, int i, char *var);
char		*join_strings(char *first, char *second, char *third);
void		free_expansion_memory(t_expansion *strings, char *var, char *str);

#endif