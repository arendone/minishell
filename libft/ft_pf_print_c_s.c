/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_c_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:47:53 by marvin            #+#    #+#             */
/*   Updated: 2022/02/10 13:34:55 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pf_print_str_width(char *str, int len, t_print *t_spec)
{
	if (!(t_spec->dash) && !(t_spec->zero))
	{
		ft_pf_print_spaces(t_spec->width_details - len);
		ft_putnstr_fd(str, 1, len);
	}
	if (t_spec->dash)
	{
		ft_putnstr_fd(str, 1, len);
		ft_pf_print_spaces(t_spec->width_details - len);
	}
	if (!(t_spec->dash) && (t_spec->zero))
	{
		ft_pf_print_zeros(t_spec->width_details - len);
		ft_putnstr_fd(str, 1, len);
	}
	return (t_spec->width_details);
}

int	ft_pf_print_char(int i, t_print *t_spec)
{
	char	c;

	c = (char) va_arg(t_spec->args, int);
	if (t_spec->width && !(t_spec->dash))
		ft_pf_print_spaces(t_spec->width_details - 1);
	ft_putchar_fd(c, 1);
	if (t_spec->width && t_spec->dash)
		ft_pf_print_spaces(t_spec->width_details - 1);
	t_spec->len_total = t_spec->len_total
		+ ft_maximum_sizet(2, 1, t_spec->width_details);
	return (i + 1);
}

int	ft_pf_print_percentage(int i, t_print *t_spec)
{
	char	c;

	c = '%';
	if (t_spec->width && !(t_spec->dash))
	{
		if (t_spec->zero == true)
			ft_pf_print_zeros(t_spec->width_details - 1);
		else
			ft_pf_print_spaces(t_spec->width_details - 1);
	}
	ft_putchar_fd(c, 1);
	if (t_spec->width && t_spec->dash)
		ft_pf_print_spaces(t_spec->width_details - 1);
	t_spec->len_total = t_spec->len_total
		+ ft_maximum_sizet(2, 1, t_spec->width_details);
	return (i + 1);
}

size_t	ft_pf_print_null(t_print *t_spec)
{
	size_t	len;

	if (!(t_spec->precision))
		len = 6;
	else
		len = ft_minimum_sizet(2, 6, t_spec->precision_details);
	if (t_spec->width_details > len)
		len = ft_pf_print_str_width("(null)", len, t_spec);
	else
		ft_putnstr_fd("(null)", 1, len);
	t_spec->len_total = t_spec->len_total + len;
	return (len);
}

int	ft_pf_print_str(int i, t_print *t_spec)
{
	char	*str;
	size_t	len;

	str = va_arg(t_spec->args, char *);
	if (!str)
		len = ft_pf_print_null(t_spec);
	else
	{
		if (!(t_spec->precision))
			len = ft_strlen(str);
		else
			len = ft_minimum_sizet(2, ft_strlen(str),
					t_spec->precision_details);
		if (t_spec->width_details > len)
			len = ft_pf_print_str_width(str, len, t_spec);
		else
			ft_putnstr_fd(str, 1, len);
		t_spec->len_total = t_spec->len_total + len;
	}
	return (i + 1);
}
