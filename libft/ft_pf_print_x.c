/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:40:36 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/10 15:08:43 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_unum(unsigned int n)
{
	size_t	digits;

	digits = 1;
	while (n / 16)
	{
		digits++;
		n /= 16;
	}
	return (digits);
}

static void	ft_putnum_base(unsigned int n, int fd, char *base)
{
	if (n / 16)
		ft_putnum_base(n / 16, fd, base);
	ft_putchar_fd(base[n % 16], fd);
}

static size_t	print_numu_sign(unsigned int num, size_t len, t_print *t_spec)
{
	size_t	count;

	count = 0;
	if ((t_spec->number) && (num != 0))
		count += write(1, "0x", 2);
	if (len > 0)
	{
		if (t_spec->precision_details > len)
		{
			ft_pf_print_zeros(t_spec->precision_details - len);
			count += (t_spec->precision_details - len);
		}
		ft_putnum_base(num, 1, "0123456789abcdef");
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

int	ft_pf_print_x(int i, t_print *t_spec)
{
	unsigned int	num;
	size_t			len;
	size_t			max;

	num = va_arg(t_spec->args, unsigned int);
	len = len_unum(num);
	if ((num == 0) && (t_spec->precision) && (t_spec->precision_details == 0))
		len = 0;
	max = ft_maximum_sizet(2, len, t_spec->precision_details);
	if ((t_spec->number) && (num != 0))
		max = max + 2;
	if (!t_spec->precision)
		t_spec->precision_details = 1;
	if (t_spec->width_details > max)
		len = p_w(num, len, max, t_spec);
	else
		len = print_numu_sign(num, len, t_spec);
	t_spec->len_total += len;
	return (i + 1);
}
