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

int ff_atoi(char* str)
{
    int i;
    i = 0;
}


int main(int argc,char** argv)
{
    if(argc <= 1 || !argv[1][0])
        return 1;
    
    char* args;
    char** two_d;
    int i = 0;

    args = join_args(argc,argv);

    two_d = split_args(args);

    while(two_d[i])
    {
        printf("%s\n",two_d[i]);
        free(two_d[i]);
        i++;
    }
    
    free(two_d);
    free(args);
    
    return 0;
}