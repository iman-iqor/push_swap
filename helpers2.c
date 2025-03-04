#include"header.h"


char	*ft_sstrjoin(char *save, char *buff)
{
	int		len;
	char	*str;
	size_t		i;
	size_t		j;

	if (!save && !buff)
		return (NULL);
	if (!save && buff)
		return (ft_strdup(buff));
	if (save && !buff)
		return (ft_strdup(save));
	len = ft_strlen(save) + ft_strlen(buff);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (save[++i] && i < ft_strlen(save))
		str[i] = save[i];
	j = 0;
	while (buff[j] && j < ft_strlen(buff))
		str[i++] = buff[j++];
	str[i] = 0;
	free(save);
	return (str);
}

int is_it_alpha(char* str)
{
    int i;
    i = 0;
    if(!str[i])
        return 1;
    while(str[i])
    {
        if(!(((str[i] >= '0' && str[i] <= '9') || str[i] == '-') ) )
        {
            return 1;
        }
        i++;
    }
    return 0;
}
void check_int_overflow(long number,t_stack_list *list,char **two_d,char* args)
{
    if(number > INT_MAX || number < INT_MIN)
    {
        write(2,"Error\n",6);
        free_list(list);
        ftt_free(two_d);
        free(args);
    
        exit(1);
    }
}
void else_of_atoi(t_stack_list** list,char** two_d,char* args)
{
        write(2,"Error\n",6);
        free_list(*list);
        ftt_free(two_d);
        free(args);
    
        exit(1);
}

int ff_atoi(char* str,t_stack_list *list,char **two_d,char* args)
{
    int i;
    long result;
    int signe;
    i = 0;
    result= 0;
    signe = 1;
    
    while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
    if(is_it_alpha(str))
        else_of_atoi(&list,two_d,args);
    
    i = 0;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            signe = -1;
         i++;
    }

    if (!(str[i] >= '0' && str[i] <= '9'))
        else_of_atoi(&list, two_d, args);
    while(str[i]>= '0' && str[i] <= '9')
    {
        result = result *10 + str[i] - 48;
        check_int_overflow(result * signe,list,two_d,args);
        i++;
    }
    return ((int)(result * signe));
}


