#include"header.h"

int lst_size(t_stack_list* list)
{
    int i;
    i = 0;
    while(list)
    {
        list = list->next;
        i++;
    }
    return i;
}

void is_lst_size(t_stack_list** list,char** two_d,char* args)
{
    if(lst_size(*list) == 1)
    {
        free_list(*list);
        ftt_free(two_d);
        free(args);
        exit(1);
    }
}
