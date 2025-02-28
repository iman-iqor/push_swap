#include"header.h"

int is_duplicated(t_stack_list *list)
{
    while(list && list->next)
    {
        if(list->number == list->next->number)
        {
            return 1;
        }
        list = list->next;
    }
    return 0;
}
void check_is_duplicated(int value,t_stack_list** list,char** two_d,char* args)
{
    if(value)
    {
        ft_putstr("ERROR","\n");
        print_list(*list);
        free_list(*list);
        ftt_free(two_d);
        free(args);
        exit(1);
    }
}
int main(int argc,char** argv)
{
    if(argc <= 1 || !argv[1][0])
        return 1;
    
    char* args;
    char** two_d;
    int i = 0;
    t_stack_list *list;
    list = NULL;
    

    args = join_args(argc,argv);
    two_d = split_args(args);
    while(two_d[i])
    {
        append_node(&list,ff_atoi(two_d[i],list,two_d,args));
        i++;
    } 
    check_is_sorted(is_sorted(list),&list,two_d,args);
    check_is_duplicated(is_duplicated(list),&list,two_d,args);
    sa(&list);
    print_list(list);
    free_list(list);
    ftt_free(two_d);
    free(args);
    
    return 0;
}
