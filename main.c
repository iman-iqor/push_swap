#include"header.h"

int is_sorted(t_stack_list *list)
{

    while(list && list->next)
    {
        
        if(list->number > list->next->number)
        {
            return 0;
        }
        list = list->next;
    }
 
    return 1;

}

int main(int argc,char** argv)
{
    if(argc <= 1 || !argv[1][0])
        return 1;
    
    char* args;
    char** two_d;
    int i = 0;
    t_stack_list *list;
    t_stack_list *test;

    args = join_args(argc,argv);
    two_d = split_args(args);
    while(two_d[i])
    {
        append_node(&list,ff_atoi(two_d[i],list,two_d,args));
        i++;
    }
    test = list;
    if(is_sorted(test))
    {
        ft_putstr("ERROR","\n");
        return 0;
    }
    print_list(list);
    free_list(list);
    ft_free(two_d);
    free(args);
    
    return 0;
}
