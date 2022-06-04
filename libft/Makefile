# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 16:20:05 by arendon-          #+#    #+#              #
#    Updated: 2022/05/23 16:49:50 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

HDR_PATH= includes
OBJ_PATH= obj

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_minimum_sizet.c ft_maximum_sizet.c ft_putnstr_fd.c \
ft_freearray.c ft_strtrim_ver2.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_atof.c \
ft_pf_init_reset_struct.c ft_pf_checkflags.c ft_pf_print_c_s.c \
ft_pf_print_d.c ft_pf_printf_aux.c ft_pf_print_u.c ft_pf_checkconversion.c \
ft_pf_print_x_upper.c ft_pf_print_x.c ft_pf_print_p.c ft_printf.c \

HDR_NAME= libft.h
HDR = $(addprefix $(HDR_PATH)/,$(HDR_NAME))

OBJ_NAME= $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
H_FLAG= -I $(HDR_PATH)

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)
	@echo "	Compilation of  $(NAME):  \033[1;32mOK\033[m"

$(OBJ_PATH)/%.o:  %.c $(HDR)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(H_FLAG)  -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;33m>> all .o files in libft are deleted.\033[0m" 

fclean: clean
	rm -f $(NAME)
	@echo "\033[0;31m>> $(NAME) is deleted.\033[0m" 

re: fclean $(NAME)
