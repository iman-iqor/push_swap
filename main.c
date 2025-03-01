#include"header.h"

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
	if (n2->number > n1->number && n2->number > n3->number && n1->number > n3->number)
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

void	push_swap(t_stack_list **a, t_stack_list **b)
{
	int	*arr;
	int	len_a;

	if (!a || !(*a) || !b)
		return ;
	len_a = ft_lstsize(*a);
	if (len_a <= 1)
		return ;
	arr = create_sorted_arr(*a);
	if (arr == NULL)
		return (free_stack(a), write(2, "Error\n", 6), exit(1));
	push_to_b(a, b, arr, len_a);
	free(arr);
	push_to_a(a, b);
}


int main(int argc,char** argv)
{
    if(argc <= 1 || !argv[1][0])
        return 1;
    
    char* args;
    char** two_d;
    t_stack_list *a;
    t_stack_list *b;
    a = NULL;
    b = NULL;

    args = join_args(argc,argv);
    two_d = split_args(args);
     
    create_stack_a(two_d,&a,args);
    check_is_sorted(is_sorted(a),&a,two_d,args);
    check_is_duplicated(is_duplicated(a),&a,two_d,args);
    
    is_lst_size(&a,two_d, args);
    if(lst_size(a) <= 5)
    {
        sort_five(&a,&b);
    }
	

    print_list(a);
    free_list(a);
    ftt_free(two_d);
    free(args);
    
    return 0;
}
