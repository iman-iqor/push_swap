#include"header.h"



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
