/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:47:42 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/18 14:20:39 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	temp = *lst;
	if (*lst == NULL)
		return ;
	while (temp != NULL)
	{
		head = temp->next;
		del(temp->content);
		free (temp);
		temp = head;
	}
	*lst = NULL;
}
