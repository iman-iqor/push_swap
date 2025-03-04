/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:00:51 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/04 22:02:59 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_arr(int *arr, int len)
{
	int(i), (j), (tmp);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*create_sorted_arr(t_stack_list *a)
{
	int	len;
	int	*arr;
	int	i;

	len = lst_size(a);
	arr = malloc(len * sizeof(int));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = a->number;
		i++;
		a = a->next;
	}
	sort_arr(arr, len);
	return (arr);
}

void	push_swap(t_stack_list **a, t_stack_list **b)
{
	int	*arr;
	int	len_a;

	if (!a || !(*a) || !b)
		return ;
	len_a = lst_size(*a);
	if (len_a <= 1)
		return ;
	arr = create_sorted_arr(*a);
	if (arr == NULL)
		return (free_list(*a), write(2, "Error\n", 6), exit(1));
	push_to_b(a, b, arr, len_a);
	free(arr);
	push_to_a(a, b);
}
