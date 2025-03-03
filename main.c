#include"header.h"



int	max_ind(t_stack_list **b)
{
	t_stack_list	*go;
	int			max;
	int			position_of_max;
	int			position;

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
	int (i), (chunk);
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







void	sort_arr(int *arr, int len)
{
	int (i), (j), (tmp);
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
    check_is_duplicated(is_duplicated(a),&a,two_d,args);
    check_is_sorted(is_sorted(a),&a,two_d,args);
    
    is_lst_size(&a,two_d, args);
    if(lst_size(a) <= 5)
    {
        sort_five(&a,&b);
    }
	else
	{
		push_swap(&a,&b);
	}
	

    // print_list(a);
    free_list(a);
    ftt_free(two_d);
    free(args);
    
    return 0;
}
