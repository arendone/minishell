/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_checkconversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:07:11 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/18 14:29:43 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pf_print_format(const char *format, int i, t_print *t_spec)
{
	int	count;

	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_pf_flags_characters(format, i, t_spec);
			while (ft_strchr("csdiupxX%", format[i]) == NULL)
				i++;
			i = ft_pf_check_conversion(format, i, t_spec);
			ft_pf_spec_reset(t_spec);
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
	return (count);
}

int	ft_pf_check_conversion(const char *format, int i, t_print *t_spec)
{
	if (format[i] == 'd' || format[i] == 'i')
		i = ft_pf_print_d(i, t_spec);
	else if (format[i] == 'c')
		i = ft_pf_print_char(i, t_spec);
	else if (format[i] == 's')
		i = ft_pf_print_str(i, t_spec);
	else if (format[i] == '%')
		i = ft_pf_print_percentage(i, t_spec);
	else if (format[i] == 'u')
		i = ft_pf_print_unsigned(i, t_spec);
	else if (format[i] == 'x')
		i = ft_pf_print_x(i, t_spec);
	else if (format[i] == 'X')
		i = ft_pf_print_upperx(i, t_spec);
	else if (format[i] == 'p')
		i = ft_pf_print_p(i, t_spec);
	return (i);
}
