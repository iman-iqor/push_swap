#include "header.h"

void	swap(t_stack_list **list)
{
	t_stack_list	*first;
	t_stack_list	*second;

	if (!*list || !(*list)->next)
	{
		return ;
	}
	first = *list;
	second = (*list)->next;
	first->next = second->next;
	second->next = first;
	(*list) = second;
}

void	sa(t_stack_list **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_list **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_list **stack_a, t_stack_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
