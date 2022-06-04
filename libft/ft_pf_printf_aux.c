/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_printf_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:16:20 by marvin            #+#    #+#             */
/*   Updated: 2022/02/10 13:35:33 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pf_print_zeros(int zeros)
{
	int	j;

	j = 0;
	while (j < zeros)
	{
		ft_putchar_fd('0', 1);
		j++;
	}
	return (zeros);
}

int	ft_pf_print_spaces(int spaces)
{
	int	j;

	j = 0;
	while (j < spaces)
	{
		ft_putchar_fd(' ', 1);
		j++;
	}
	return (spaces);
}
