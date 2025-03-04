#include "header.h"

// The first element becomes the last one
void	r(t_stack_list **list)
{
	t_stack_list	*tmp;
	t_stack_list	*tmp2;

	if (!list || !(*list) || !((*list)->next))
		return ;
	tmp = *list;
	tmp2 = *list;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	*list = (*list)->next;
	tmp->next = NULL;
	tmp2->next = tmp;
}

void	ra(t_stack_list **a)
{
	r(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_list **b)
{
	r(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_list **a, t_stack_list **b)
{
	r(a);
	r(b);
	write(1, "rr\n", 3);
}
