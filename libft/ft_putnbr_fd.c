/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:47:55 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/14 16:00:18 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	d;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	i = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	if (n <= 9)
	{
		d = '0' + n;
		write(fd, &d, 1);
	}
	else
	{
		ft_putnbr_fd(((n - (n % 10)) / 10), fd);
		d = '0' + (n % 10);
		write(fd, &d, 1);
	}
}
