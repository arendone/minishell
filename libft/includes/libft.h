/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:19:59 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/18 14:30:06 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

typedef struct s_print
{
	va_list	args;
	bool	dash;
	bool	zero;
	bool	number;
	bool	space;
	bool	sign;
	bool	width;
	size_t	width_details;
	bool	precision;
	size_t	precision_details;
	int		len_total;
}t_print;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strtrim_ver2(char const *s1, char c);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *newe);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *newe);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
size_t	ft_maximum_sizet(size_t n, ...);
size_t	ft_minimum_sizet(size_t n, ...);
void	ft_putnstr_fd(char *s, int fd, int n);
void	ft_freearray(char **array);
double	ft_atof(char *str);

/* ft_printf funtions */
int		ft_printf(const char *fmt, ...);
t_print	*ft_pf_spec_init(t_print *t_spec);
t_print	*ft_pf_spec_reset(t_print *t_spec);
void	*ft_pf_flags_characters(const char *format, int i, t_print *t_spec);
int		ft_pf_print_format(const char *format, int i, t_print *t_spec);
int		ft_pf_check_conversion(const char *format, int i, t_print *t_spec);
int		ft_pf_flag_precision(const char *format, int i, t_print *t_spec);
int		ft_pf_flag_width(const char *format, int i, t_print *t_spec);
int		ft_pf_print_char(int i, t_print *t_spec);
int		ft_pf_print_str(int i, t_print *t_spec);
int		ft_pf_print_percentage(int i, t_print *t_spec);
int		ft_pf_print_d(int i, t_print *t_spec);
int		ft_pf_print_unsigned(int i, t_print *t_spec);
int		ft_pf_print_x(int i, t_print *t_spec);
int		ft_pf_print_upperx(int i, t_print *t_spec);
int		ft_pf_print_p(int i, t_print *t_spec);
int		ft_pf_print_zeros(int zeros);
int		ft_pf_print_spaces(int spaces);
int		ft_pf_print_str_width(char *str, int len, t_print *t_spec);
size_t	ft_pf_print_null(t_print *t_spec);

#endif