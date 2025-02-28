#include"header.h"

int is_sorted(t_stack_list *list)
{
    while( list->next)
    {
        if(list->number > list->next->number)
            return 0;
        list = list->next;
    }
    return 1;

}
void check_is_sorted(int value,t_stack_list **list,char** two_d,char* args)
{
    if(value)
    {
        ft_putstr("ERROR sorted","\n");
        print_list(*list);
        free_list(*list);
        ftt_free(two_d);
        free(args);
        exit(1);
    }
}