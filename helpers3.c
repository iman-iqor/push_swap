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
    // printf("NULL\n");
}

void free_list(t_stack_list *head)
{
    t_stack_list *tmp;
    while(head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
char* join_args(int argc,char** argv)
{
    int i;
    char* args; 
    i = 1;
    args  = NULL;
    
    while(argv[i])
    {
        args = ft_sstrjoin(args,argv[i]);
        if(i != argc -1)
            args = ft_sstrjoin(args," ");
        i++;
    }
    return args;
}

void	ft_putstr(char *s1, char *s2)
{
	if (!s1)
		write(2, "(null)", 6);
	else
		write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
}
