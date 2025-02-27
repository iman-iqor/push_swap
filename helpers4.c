#include"header.h"

void	ft_putstr(char *s1, char *s2)
{
	if (!s1)
		write(2, "(null)", 6);
	else
		write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
}

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
void check_is_sorted(int value,t_stack_list **list,char** two_d,char* args)
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