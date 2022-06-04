/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:09:38 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/18 17:34:27 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

void	print_redir(t_program *pro_head)
{
	t_redir	*current;

	printf("PRINT CONTENT OF REDIR LIST\n");
	current = pro_head->redir_head;
	while (current)
	{
		printf("type:  %d, file: %s\n", current->type, current->file);
		current = current->next;
	}
}
