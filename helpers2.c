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
    while(str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            return 1;
        i++;
    }
    return 0;
}


long ff_atoi(char* str)
{
    long i;
    long result;
    long signe;
    i = 0;
    result= 0;
    signe = 1;
    if(!is_it_alpha(str))
    {
        if(str[i] == '-' || str[i] == '+')
        {
        if(str[i] == '-')
            signe = -1;
        i++;
        }
        while(str[i]>= '0' && str[i] <= '9')
        {
            result = result *10 + str[i] - 48;
            i++;
        }
        return result * signe;
    }
    else
        return 1;
    
    
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