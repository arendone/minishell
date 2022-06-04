/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:14:23 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/10 14:51:04 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newe)
{
	t_list		*last;

	if (newe == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = newe;
		newe->next = NULL;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = newe;
}
