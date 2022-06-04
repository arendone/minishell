/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_init_reset_struct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:07:09 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/10 13:34:49 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_print	*ft_pf_spec_init(t_print *t_spec)
{
	t_spec->number = false;
	t_spec->zero = false;
	t_spec->dash = false;
	t_spec->space = false;
	t_spec->sign = false;
	t_spec->width = false;
	t_spec->width_details = 0;
	t_spec->precision = false;
	t_spec->precision_details = 0;
	t_spec->len_total = 0;
	return (t_spec);
}

t_print	*ft_pf_spec_reset(t_print *t_spec)
{
	t_spec->number = false;
	t_spec->zero = false;
	t_spec->dash = false;
	t_spec->space = false;
	t_spec->sign = false;
	t_spec->width = false;
	t_spec->width_details = 0;
	t_spec->precision = false;
	t_spec->precision_details = 0;
	return (t_spec);
}
