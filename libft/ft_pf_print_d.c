/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:59:05 by marvin            #+#    #+#             */
/*   Updated: 2022/02/10 13:35:03 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_int(int n)
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

static size_t	print_prec(int num, size_t len, size_t counter, t_print *t_spec)
{
	if (t_spec->precision_details > len)
	{
		if (num == -2147483648)
			write(1, "-", 1);
		ft_pf_print_zeros(t_spec->precision_details - len);
		counter += (t_spec->precision_details - len);
	}
	if ((num == -2147483648) && (t_spec->precision_details > len))
		write(1, "2147483648", 10);
	else
		ft_putnbr_fd(num, 1);
	return (counter);
}

static size_t	print_sign(int num, size_t len, t_print *t_spec)
{
	size_t	counter;

	counter = 0;
	if (num == -2147483648)
		counter ++;
	else if ((t_spec->sign == true) && (num >= 0))
		counter += write(1, "+", 1);
	else if (num < 0)
	{
		counter += write(1, "-", 1);
		num = num * (-1);
	}
	else if (t_spec->space == true)
		counter += write(1, " ", 1);
	if (len > 0)
		counter = print_prec(num, len, counter, t_spec);
	return (len + counter);
}

static size_t	print_width(int num, size_t len, size_t max, t_print *t_spec)
{
	if (!t_spec->dash)
	{
		if ((t_spec->zero == true) && (t_spec->precision == false))
		{
			if (num < 0)
				t_spec->precision_details = t_spec->width_details - 1;
			else
				t_spec->precision_details = t_spec->width_details;
		}
		else
			ft_pf_print_spaces(t_spec->width_details - max);
		len = print_sign(num, len, t_spec);
	}
	else
	{
		len = print_sign(num, len, t_spec);
		ft_pf_print_spaces(t_spec->width_details - max);
	}
	return (t_spec->width_details);
}

int	ft_pf_print_d(int i, t_print *t_spec)
{
	int		num;
	size_t	len;
	size_t	max;

	num = va_arg(t_spec->args, int);
	len = ft_len_int(num);
	if ((num == 0) && (t_spec->precision) && (t_spec->precision_details == 0))
		len = 0;
	max = ft_maximum_sizet(2, len, t_spec->precision_details);
	if ((num < 0) || (t_spec->sign == true) || (t_spec->space == true))
		max++;
	if (!t_spec->precision)
		t_spec->precision_details = 1;
	if (t_spec->width_details > max)
		len = print_width(num, len, max, t_spec);
	else
		len = print_sign(num, len, t_spec);
	t_spec->len_total += len;
	return (i + 1);
}
