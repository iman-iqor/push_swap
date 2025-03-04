/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:02:05 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/04 22:03:29 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	lst_size(t_stack_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	is_lst_size(t_stack_list **list, char **two_d, char *args)
{
	if (lst_size(*list) == 1)
	{
		free_list(*list);
		ftt_free(two_d);
		free(args);
		exit(1);
	}
}
