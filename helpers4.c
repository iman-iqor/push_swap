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
        write(2,"Error\n",6);
        free_list(*list);
        ftt_free(two_d);
        free(args);
        exit(1);
    }
}
int is_duplicated(t_stack_list *list)
{
    t_stack_list	*tmp1;
	t_stack_list	*tmp2;

	tmp1 = list;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		while (tmp2 != NULL)
		{
			if (tmp2->number == tmp1->number)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}
void check_is_duplicated(int value,t_stack_list** list,char** two_d,char* args)
{
    if(value)
    {
        write(2,"Error\n",6);
        free_list(*list);
        ftt_free(two_d);
        free(args);
        exit(1);
    }
}

void create_stack_a(char** two_d,t_stack_list** list,char* args)
{
    int i;
    i = 0;
    while(two_d[i])
    {
        append_node(list,ff_atoi(two_d[i],*list,two_d,args));
        i++;
    }
}
