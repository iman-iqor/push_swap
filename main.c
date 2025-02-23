#include"header.h"


t_stack_list *create_node(int number)
{
    t_stack_list *node;
    node = (t_stack_list*) malloc(sizeof(t_stack_list));
    if(!node)
    {
        ft_putstr("memory alocation","failed\n");
        exit (1);
    }
    node->number = number;
    node->next = NULL;
    return node;
}
void append_node(t_stack_list **head,int number)
{
    t_stack_list *node;
    node = create_node(number);
    if(*head == NULL)
    {
        *head = node;
        return;
    }
    t_stack_list *current;
    current = *head;
    while(current->next)
    {
        current=current->next;
    }
    current->next = node;
}
void print_list(t_stack_list *list)
{
    while(list)
    {
        printf("%i\n",list->number);
        list= list->next;
    }
    printf("NULL\n");
}



int main(int argc,char** argv)
{
    if(argc <= 1 || !argv[1][0])
        return 1;
    
    char* args;
    char** two_d;
    int i = 0;
    t_stack_list *list;

    args = join_args(argc,argv);

    two_d = split_args(args);

    while(two_d[i])
    {
        printf(" char ==> %s\n",two_d[i]);
        printf(" number ==> %li\n",ff_atoi(two_d[i]));
        append_node(&list,ff_atoi(two_d[i]));
        free(two_d[i]);
        i++;
    }
    print_list(list);

    free(two_d);
    free(args);
    
    return 0;
}
