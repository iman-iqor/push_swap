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
