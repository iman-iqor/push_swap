#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include "stdio.h"
#include <stdlib.h>
#include "./libft/libft.h"
#include <limits.h>

typedef struct s_stack_list
{
    int number;
    int index;
    struct s_stack_list *next;
} t_stack_list;

typedef struct s_state
{
    int i ;
    int cw ;
    int start;
    int end;
    int k;
    char **two_d ;
}   t_state;

char *ft_sstrjoin(char *save, char *buff);
char **split_args(char *args);
char *ft_strncopy(char *str, int start, int end);
char *ft_free(char **arr);
int count_word(char* args);
int ff_atoi(char* str,t_stack_list *list,char **two_d,char* args);
int is_it_alpha(char* str);
char* join_args(int argc,char** argv);
void	ft_putstr(char *s1, char *s2);
void free_list(t_stack_list *head);


#endif