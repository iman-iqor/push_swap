#include "header.h"

int	max_ind(t_stack_list **b)
{
	t_stack_list	*go;
	int				max;
	int				position_of_max;
	int				position;

	go = *b;
	position = 0;
	max = go->number;
	position_of_max = 0;
	while (go != NULL)
	{
		if (go->number > max)
		{
			max = go->number;
			position_of_max = position;
		}
		go = go->next;
		position++;
	}
	return (position_of_max);
}

void	push_to_a(t_stack_list **a, t_stack_list **b)
{
	int	len_b;
	int	p;

	if (!a || !b || !*b)
		return ;
	len_b = lst_size(*b);
	while (len_b > 0)
	{
		p = max_ind(b);
		if (p <= len_b / 2)
		{
			while (p-- > 0)
				rb(b);
		}
		else
		{
			while (p++ < len_b)
				rrb(b);
		}
		pa(a, b);
		len_b--;
	}
}
