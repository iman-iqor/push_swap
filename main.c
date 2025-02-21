#include"header.h"
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
int count_word(char* args)
{
    int i;
    i = 0;
    int cw;
    cw  = 0;
    while(args[i])
    {
        while(args[i] != " " )
            i++;
        if(args[i] == )
    }
}
char** split_args(char* args)
{
    int i = 0;
    
}

int main(int argc,char** argv)
{
    if(argc <= 1 || !argv[1][0])
        return 1;
    
    char* args;
    char** numbers;
    args = join_args(argc,argv);
    printf("%s\n",args);
    numbers = split_args(args);
    free(args);
    return 0;
}