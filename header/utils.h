/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:08:27 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/20 22:20:25 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

# include "../libft/includes/libft.h"

/*	COMPARE STRINGS */
int		is_equal_string(const char *s1, const char *s2);
int		is_equal_string_with_letter_casing(const char *s1, const char *s2);
char	*str_copy(char *str);

#endif