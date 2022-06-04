NAME	:= minishell
CC		:= gcc
FLAGS	:= -Wall -Wextra -Werror -g
FT		:= -Ilibft -Llibft -lft
RM		:= rm -f
# -fsanitize=address
O		= obj/
E		= exit/
T		= tokenizer/
P		= parser/
N		= env/
X		= executor/
B		= builtins/
S		= signals/
U		= utils/
M		= shell/

OBJS	= 	$(patsubst %.c, $O%.o, $(SRCS))
SRCS	:= main.c \
			$Ssignals.c \
			$Eerror.c \
			$Tcheck_input.c \
			$Tappend_token.c \
			$Tcreate_token.c \
			$Tfree_token_list.c \
			$Ttokenizer.c \
			$Ttokenizer_utils.c \
			$Tremove_quotes.c \
			$Terror_handling.c \
			$Texpansion_utils.c \
			$Texpansion.c \
			$Pcall_redirection.c \
			$Pcreate_programs.c \
			$Pmemory_program.c \
			$Pmemory_redirection.c \
			$Pparser_utils.c \
			$Pset_redirection_type.c \
			$Nadd_env_node.c \
			$Ncopy_env_list.c \
			$Ncopy_env_node.c \
			$Ncreate_env_array.c \
			$Ncreate_env_list.c \
			$Ncreate_env_node.c \
			$Ncreate_key_value_pair.c \
			$Ndelete_env_node.c \
			$Nfill_env_node.c \
			$Nfree_env_array.c \
			$Nfree_env_list.c \
			$Nfree_env_node.c \
			$Nfree_key_value_pair.c \
			$Nget_keymatch_env_node.c \
			$Nget_keymatch_value.c \
			$Nget_last_env_node.c \
			$Nis_key_existing.c \
			$Nis_key_valid.c \
			$Nprint_env_array.c \
			$Nprint_env_list_sorted.c \
			$Nprint_env_list.c \
			$Nreplace_env_node.c \
			$Nupdate_env_cmd_path.c \
			$Nupdate_env_oldpwd.c \
			$Nupdate_env_pwd.c \
			$Xexecute_child.c \
			$Xexecute_parent.c \
			$Xexecutor.c \
			$Xpathfinding.c \
			$Xpipe.c \
			$Xredirections.c \
			$Xheredoc.c \
			$Xstreams.c \
			$Bbuiltin.c \
			$Bcd.c \
			$Becho.c \
			$Benv.c \
			$Bexport.c \
			$Bpwd.c \
			$Bunset.c \
			$Uis_equal_string.c \
			$Mcheck_minishell_input.c \
			$Mhandle_minishell_data.c \
			$Mminishell.c \
			$Mmodify_shlvl.c \
			$Mread_minishell_input.c \

# JOKO
# INCRL		= -I /goinfre/$(USER)/.brew/opt/readline/include
# LIBRL		= -lreadline -L /goinfre/$(USER)/.brew/opt/readline/lib
# LIBRARIES	=-Llibft -lft $(LIBRL)
# INCLUDES	=-I ./header -Ilibft $(INCRL)

# ANAHI
INCRL		= -I /Users/$(USER)/.brew/opt/readline/include
LIBRL		= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib
LIBRARIES	= -Llibft -lft $(LIBRL)
INCLUDES	= -I ./header -Ilibft $(INCRL)

FT_PATH = ./libft/

.PHONY: all clean fclean re

all: $(NAME)

# Linking
$(NAME): libft/libft.a $(OBJS)
	@echo "\033[1;32mMiniShell Ƹ̵̡Ӝ̵̨̄Ʒ\033[1;0m\033[32m linking...\033[0m"
	@$(CC) $(FLAGS) $(OBJS) $(LIBRARIES) -o $(NAME)
	@echo "\033[1;32mMiniShell Ƹ̵̡Ӝ̵̨̄Ʒ\033[1;0m\033[32m created.\033[0m"

# Compiling
$O%.o: %.c
			@[ -d $(O) ]	 || mkdir -p $(O)
			@[ -d $(O)$(E) ] || mkdir -p $(O)$(E)
			@[ -d $(O)$(T) ] || mkdir -p $(O)$(T)
			@[ -d $(O)$(P) ] || mkdir -p $(O)$(P)
			@[ -d $(O)$(N) ] || mkdir -p $(O)$(N)
			@[ -d $(O)$(X) ] || mkdir -p $(O)$(X)
			@[ -d $(O)$(B) ] || mkdir -p $(O)$(B)
			@[ -d $(O)$(S) ] || mkdir -p $(O)$(S)
			@[ -d $(O)$(U) ] || mkdir -p $(O)$(U)
			@[ -d $(O)$(M) ] || mkdir -p $(O)$(M)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[1;32mMiniShell Ƹ̵̡Ӝ̵̨̄Ʒ\033[1;0m\033[32m compiling...\033[0m"

clean:
	@rm -rf $(O)
	@echo "\033[1;33m>> all .o files in MiniShell Ƹ̵̡Ӝ̵̨̄Ʒ are deleted.\033[0m" 
	${MAKE} -C ${FT_PATH} clean

fclean: clean
	$(RM) $(NAME)
	@echo "\033[0;31m>> MiniShell Ƹ̵̡Ӝ̵̨̄Ʒ is deleted.\033[0m"
	${MAKE} -C ${FT_PATH} fclean

re: fclean all

libft/libft.a:
	${MAKE} -C ${FT_PATH}