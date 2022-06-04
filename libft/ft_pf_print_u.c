/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 05:29:55 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/10 13:35:15 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_unum(unsigned int n)
{
	size_t	digits;

	digits = 1;
	while (n / 10)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

static void	ft_putuinbr_fd(unsigned int n, int fd)
{
	if (n / 10)
		ft_putuinbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

static size_t	print_numu_sign(unsigned int num, size_t len, t_print *t_spec)
{
	size_t	count;

	count = 0;
	if (t_spec->sign)
		count += write(1, "+", 1);
	else if (t_spec->space == true)
		count += write(1, " ", 1);
	if (len > 0)
	{
		if (t_spec->precision_details > len)
		{
			ft_pf_print_zeros(t_spec->precision_details - len);
			count += (t_spec->precision_details - len);
		}
		ft_putuinbr_fd(num, 1);
	}
	return (len + count);
}

static size_t	p_w(unsigned int num, size_t len, size_t max, t_print *t_spec)
{
	if (!t_spec->dash)
	{
		if ((t_spec->zero == true) && (t_spec->precision == false))
			t_spec->precision_details = t_spec->width_details;
		else
			ft_pf_print_spaces(t_spec->width_details - max);
		len = print_numu_sign(num, len, t_spec);
	}
	else
	{
		len = print_numu_sign(num, len, t_spec);
		if ((t_spec->zero == true) && (t_spec->precision == false))
			ft_pf_print_zeros(t_spec->width_details - max);
		else
			ft_pf_print_spaces(t_spec->width_details - max);
	}
	return (t_spec->width_details);
}

int	ft_pf_print_unsigned(int i, t_print *t_spec)
{
	unsigned int	num;
	size_t			len;
	size_t			max;

	num = va_arg(t_spec->args, unsigned int);
	len = len_unum(num);
	if ((num == 0) && (t_spec->precision) && (t_spec->precision_details == 0))
		len = 0;
	max = ft_maximum_sizet(2, len, t_spec->precision_details);
	if ((t_spec->sign == true) || (t_spec->space == true))
		max++;
	if (!t_spec->precision)
		t_spec->precision_details = 1;
	if (t_spec->width_details > max)
		len = p_w(num, len, max, t_spec);
	else
		len = print_numu_sign(num, len, t_spec);
	t_spec->len_total += len;
	return (i + 1);
}
