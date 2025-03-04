#include "header.h"

void	help_sort_five1(t_stack_list **a)
{
	rra(a);
	sa(a);
}

void	help_sort_five2(t_stack_list **a)
{
	ra(a);
	sa(a);
}

int	find_min(t_stack_list *a)
{
	int	min;

	min = a->number;
	while (a)
	{
		if (a->number < min)
			min = a->number;
		a = a->next;
	}
	return (min);
}

int	find_second_min(t_stack_list *a, int min)
{
	int	sec_min;

	sec_min = 2147483647;
	while (a)
	{
		if (a->number > min && a->number < sec_min)
			sec_min = a->number;
		a = a->next;
	}
	return (sec_min);
}

void	sort_three(t_stack_list **a)
{
	t_stack_list	*n1;
	t_stack_list	*n2;
	t_stack_list	*n3;

	if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
		return ;
	n1 = *a;
	n2 = n1->next;
	n3 = n2->next;
	if (n2->number > n1->number && n2->number > n3->number
		&& n1->number > n3->number)
		rra(a);
	else if (n2->number > n1->number && n2->number > n3->number
		&& n1->number < n3->number)
		help_sort_five1(a);
	else if (n2->number < n1->number && n2->number < n3->number
		&& n1->number < n3->number)
		sa(a);
	else if (n2->number < n1->number && n2->number < n3->number
		&& n1->number > n3->number)
		ra(a);
	else if (n2->number < n1->number && n2->number > n3->number
		&& n1->number > n3->number)
		help_sort_five2(a);
}

void	sort_five(t_stack_list **a, t_stack_list **b)
{
	if (!a || !b || lst_size(*a) <= 1)
		return ;
	while (lst_size(*a) > 3)
	{
		if (lst_size(*a) == 5 && ((*a)->number == find_min(*a)
				|| (*a)->number == find_second_min(*a, find_min(*a))))
		{
			pb(b, a);
		}
		else if (lst_size(*a) == 4 && (*a)->number == find_min(*a))
			pb(b, a);
		else
			ra(a);
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
	if ((*a)->number > (*a)->next->number)
		sa(a);
}
