/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:49:53 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/10 13:35:08 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_unum(unsigned long int n)
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

static void	ft_putnum_base(unsigned long int n, int fd, char *base)
{
	if (n / 16)
		ft_putnum_base(n / 16, fd, base);
	ft_putchar_fd(base[n % 16], fd);
}

static size_t	print_numu_sign(unsigned long int n, size_t l, t_print *t_spec)
{
	size_t	count;

	count = 0;
	count += write(1, "0x", 2);
	if (l > 0)
	{
		if (t_spec->precision_details > l)
		{
			ft_pf_print_zeros(t_spec->precision_details - l);
			count += (t_spec->precision_details - l);
		}
	}
	ft_putnum_base(n, 1, "0123456789abcdef");
	return (l + count);
}

static size_t	p_w(unsigned long int n, size_t l, size_t max, t_print *t_spec)
{
	if (!t_spec->dash)
	{
		if ((t_spec->zero == true) && (t_spec->precision == false))
			t_spec->precision_details = t_spec->width_details;
		else
			ft_pf_print_spaces(t_spec->width_details - max);
		l = print_numu_sign(n, l, t_spec);
	}
	else
	{
		l = print_numu_sign(n, l, t_spec);
		if ((t_spec->zero == true) && (t_spec->precision == false))
			ft_pf_print_zeros(t_spec->width_details - max);
		else
			ft_pf_print_spaces(t_spec->width_details - max);
	}
	return (t_spec->width_details);
}

int	ft_pf_print_p(int i, t_print *t_spec)
{
	unsigned long int	num;
	size_t				len;
	size_t				max;

	num = (unsigned long int)va_arg(t_spec->args, void *);
	len = len_unum(num);
	max = ft_maximum_sizet(2, len, t_spec->precision_details) + 2;
	if (!t_spec->precision)
		t_spec->precision_details = 1;
	if (t_spec->width_details > max)
		len = p_w(num, len, max, t_spec);
	else
		len = print_numu_sign(num, len, t_spec);
	t_spec->len_total += len;
	return (i + 1);
}
