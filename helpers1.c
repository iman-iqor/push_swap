#include"header.h"

char	*ftt_free(char **arr)
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
    int cw;
    i = 0;
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
                ftt_free(state.two_d);
            state.k++;
        }
    }
    state.two_d[state.k] = NULL;
    return state.two_d;
}
