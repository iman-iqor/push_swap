#include"header.h"

void	rr0(t_stack_list **list)
{
	t_stack_list	*tmp;
	t_stack_list	*tmp2;

	if (!list || !(*list) || !((*list)->next))
		return ;
	tmp2 = *list;
	while (tmp2->next != NULL)
	{
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	tmp2->next = *list;
	tmp->next = NULL;
	*list = tmp2;
}

void	rra(t_stack_list **a)
{
	rr0(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_list **b)
{
	rr0(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_list **a, t_stack_list **b)
{
	rr0(a);
	rr0(b);
	write(1, "rrr\n", 4);
}