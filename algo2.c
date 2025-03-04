/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:01:01 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/04 22:03:03 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	decide_chunk(int len_a)
{
	int	chunk;

	if (len_a <= 100)
		chunk = len_a / 5;
	else if (len_a <= 500)
		chunk = len_a / 12;
	else
		chunk = len_a / 20;
	return (chunk);
}

void	incremente(int *i, int *chunk, int len)
{
	if ((*i) < len - 1)
		(*i)++;
	if ((*chunk) < len - 1)
		(*chunk)++;
}

void	check_b(t_stack_list **b)
{
	if (!b || !(*b) || !(*b)->next)
		return ;
	if ((*b)->number < (*b)->next->number)
		sb(b);
}

void	push_to_b(t_stack_list **a, t_stack_list **b, int *arr, int len_a)
{
	int(i), (chunk);
	i = 0;
	chunk = decide_chunk(len_a);
	while (a && *a != NULL)
	{
		if ((*a)->number <= arr[i])
		{
			pb(b, a);
			rb(b);
			incremente(&i, &chunk, len_a);
		}
		else if ((*a)->number <= arr[chunk])
		{
			pb(b, a);
			check_b(b);
			incremente(&i, &chunk, len_a);
		}
		else
			ra(a);
	}
}
