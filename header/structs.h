/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:39:51 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 11:55:18 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>
# include <sys/types.h>

/*
**	LIST OF TOKENS
**	A token is a sequence of characters considered a single unit by the shell.
**	They are stored in a linked list and each node contains the type and
**	how they are quoted. Also the original string before (source) and after
**	(content) quote removal and expansion. A pointer to the previous and next
**	node.
*/

typedef struct s_token
{
	int				type;
	int				quote;
	char			*source;
	char			*content;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_LESS,
	REDIR_GREAT,
	REDIR_DLESS,
	REDIR_DGREAT
}	t_toktype;

typedef enum e_state
{
	STATE_GEN,
	STATE_IN_QUOTE,
	STATE_IN_DQUOTE,
	STATE_DOLLAR
}	t_state;

/*
**	EXPANSION STRINGS
**	The expanded variable, the string before and after are stored in a struct,
**	allowing to join them easily to one string.
*/

typedef struct s_expansion_strings
{
	char	*first;
	char	*var;
	char	*last;
}	t_expansion;

/*
**	LIST OF REDIRECTIONS
**	The redirections are stored in a linked list. Each node contains the type
**	of redirection, the name of the file , the mode and a pointer to the next
**	node.
*/

typedef struct s_redir
{
	int				type;
	char			*file;
	int				mode;
	struct s_redir	*next;
}	t_redir;

typedef enum e_redirection_type
{
	ERROR,
	REDIRECTION_LEFT,
	REDIRECTION_RIGHT,
	HEREDOC,
	DOUBLE_REDIRECTION
}	t_redir_type;

/*
**	LIST OF PROGRAMS
**	The environmental variables are stored in a linked list. Each node
**	contains key, value and if an equal sign is present. A sorting value,
**	which is used for sorting the list. A pointer to the previous and next
**	node.
*/

typedef struct s_program
{
	t_token				*tok_head;
	int					n_tokens;
	pid_t				pid;
	char				**cmd_argv;
	int					nargvs;
	int					fd[2];
	t_redir				*redir_head;
	struct s_program	*next;
}	t_program;

/*
**	LIST OF ENVIRONMENTAL VARIABLES
**	The environmental variables are stored in a linked list. Each node
**	contains key, value and if an equal sign is present. A sorting value,
**	which is used for sorting the list. A pointer to the previous and next
**	node.
*/

typedef struct s_env_list
{
	char				*key;
	char				*value;
	bool				equal_sign;
	int					sorting_value;
	struct s_env_list	*prev;
	struct s_env_list	*next;
}	t_env;

enum e_env_sorting_value
{
	DEFAULT,
	EQUAL,
	CHECKED
};

/*
**	MINISHELL DATA
**	Contains necessary data the minishell needs to execute properly:
**	Prompt, number of pipes, pipe file descriptor, temporary file descriptor
**	storing the input-stream, copy of terminal STDIN and STDOUT, input string,
**	head of program list, head of environmental variable list, builtin code,
**	argc and argv.
*/

typedef struct s_minishell_data
{
	char		*prompt;
	int			pipes;
	int			pipe_fd[2];
	int			tmp_fd;
	int			stdin_fd;
	int			stdout_fd;
	char		*cmdline;
	t_program	*pro_head;
	t_env		*env_head;
	int			builtin_code;
	int			argc;
	char		**argv;
}	t_data;

#endif