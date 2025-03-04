/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:02:14 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/04 22:03:38 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pa(t_stack_list **dst, t_stack_list **src)
{
	t_stack_list	*push_node;

	if (!src || !(*src) || !dst)
		return ;
	push_node = *src;
	*src = (*src)->next;
	push_node->next = *dst;
	*dst = push_node;
	write(1, "pa\n", 3);
}

void	pb(t_stack_list **dst, t_stack_list **src)
{
	t_stack_list	*push_node;

	if (!src || !(*src) || !dst)
		return ;
	push_node = *src;
	*src = (*src)->next;
	push_node->next = *dst;
	*dst = push_node;
	write(1, "pb\n", 3);
}
