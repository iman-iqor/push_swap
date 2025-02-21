#ifndef HEADER_H
#define  HEADER_H

#include<unistd.h>
#include"stdio.h"
#include"./libft/libft.h"

typedef struct s_stack_list
{
    int number;
    int index;
} t_stack_list;

char	*ft_sstrjoin(char *save, char *buff);

#endif 