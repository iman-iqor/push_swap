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
char	*ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
char* ft_strncopy(char* str,int start,int end)
{
    int i;
    i= 0;
    char* s;
    s = malloc(end-start+1);
    while(start< end)
    {
        s[i] = str[start];
        start++;
        i++;
    }
    s[i] = 0;
    return s;
}
int count_word(char* args)
{
    int i;
    i = 0;
    int cw;
    cw  = 0;

    while(args[i])
    {
        
        while(args[i] && args[i] == ' ' )
        {
            i++;
        }
        if( args[i] && args[i] != ' ')
        {
            cw++;
        }
        while(args[i] && args[i] != ' ')
        {
            i++;
        }
            
    }

    return cw;
}

void init_state(t_state *state,char* args)
{
    state->i = 0;
    state->cw = 0;
    state->start = 0;
    state->end = 0;
    state->k = 0;
    state->cw = count_word(args);
    state->two_d = (char**) malloc((state->cw+1) * sizeof(char*));
}

char** split_args(char* args)
{
    t_state state;

    init_state(&state,args);
    if(!state.two_d)
        return NULL;
    while(args[state.i])
    {
        while(args[state.i] && args[state.i] == ' ')
            state.i++;
        state.start = state.i;

        while(args[state.i] && args[state.i ] != ' ')
            state.i++;
        state.end = state.i;
        if(state.end > state.start)
        {
            state.two_d[state.k] = ft_strncopy(args,state.start,state.end);
            if(!state.two_d[state.k])
                ft_free(state.two_d);
            state.k++;
        }
    }
    state.two_d[state.k] = NULL;
    return state.two_d;
}
