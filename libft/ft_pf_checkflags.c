/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_checkflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:52:08 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/10 13:34:44 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_pf_flags_characters(const char *format, int i, t_print *t_spec)
{
	while (ft_strchr("csdiupxX%", format[i]) == NULL)
	{
		if (format[i] == '#')
			t_spec->number = true;
		if (format[i] == '0')
			t_spec->zero = true;
		if (format[i] == '-')
			t_spec->dash = true;
		if (format[i] == ' ')
			t_spec->space = true;
		if (format[i] == '+')
			t_spec->sign = true;
		if (ft_isdigit(format[i]) || (format[i] == '*'))
			i = ft_pf_flag_width(format, i, t_spec);
		if (format[i] == '.')
			i = ft_pf_flag_precision(format, i + 1, t_spec);
		i++;
	}
	return (t_spec);
}

static size_t	ft_pf_width_details(t_print *t_spec)
{
	int				width;

	width = va_arg((t_spec->args), int);
	if (width < 0)
	{
		width = width * (-1);
		t_spec->dash = true;
		t_spec->zero = false;
	}
	return ((size_t)width);
}

int	ft_pf_flag_width(const char *format, int i, t_print *t_spec)
{
	size_t	width;

	width = 0;
	t_spec->width = true;
	if (format[i] == '*')
	{
		t_spec->width_details = ft_pf_width_details(t_spec);
		i++;
	}
	if (ft_isdigit(format[i]))
	{
		while (ft_isdigit(format[i]))
		{
			width = width * 10 + (format[i] - '0');
			i++;
		}
		t_spec->width_details = width;
	}
	return (i - 1);
}

static size_t	ft_pf_precision_details(t_print *t_spec)
{
	int				precision;

	precision = va_arg((t_spec->args), int);
	if (precision < 0)
	{
		precision = 0;
		t_spec->precision = false;
	}
	return ((size_t)precision);
}

int	ft_pf_flag_precision(const char *format, int i, t_print *t_spec)
{
	size_t	precision;

	t_spec->precision = true;
	precision = 0;
	if (format[i] == '*')
	{
		t_spec->precision_details = ft_pf_precision_details(t_spec);
		i++;
	}
	else
	{
		while (ft_isdigit(format[i]))
		{
			precision = precision * 10 + (format[i] - '0');
			i++;
		}
		t_spec->precision_details = precision;
	}
	return (i - 1);
}
