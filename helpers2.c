/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:01:33 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/04 22:03:18 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_sstrjoin(char *save, char *buff)
{
	int		len;
	char	*str;
	size_t	i;
	size_t	j;

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

int	is_it_alpha(char *str, int *i)
{
	if (!str[*i])
		return (1);
	while (str[*i])
	{
		if (!(((str[*i] >= '0' && str[*i] <= '9'))))
		{
			return (1);
		}
		(*i)++;
	}
	return (0);
}

void	check_int_overflow(long number, t_stack_list *list, char **two_d,
		char *args)
{
	if (number > INT_MAX || number < INT_MIN)
	{
		write(2, "Error\n", 6);
		free_list(list);
		ftt_free(two_d);
		free(args);
		exit(1);
	}
}

void	else_of_atoi(t_stack_list **list, char **two_d, char *args)
{
	write(2, "Error\n", 6);
	free_list(*list);
	ftt_free(two_d);
	free(args);
	exit(1);
}

int	ff_atoi(char *str, t_stack_list *list, char **two_d, char *args)
{
	t_atoa_state	vars;

	vars.i = 0;
	vars.result = 0;
	vars.signe = 1;
	while (str[vars.i] == '\t' || str[vars.i] == '\n' || str[vars.i] == '\v'
		|| str[vars.i] == '\f' || str[vars.i] == '\r' || str[vars.i] == ' ')
		vars.i++;
	vars.i = 0;
	if (str[vars.i] == '-' || str[vars.i] == '+')
	{
		if (str[vars.i] == '-')
			vars.signe = -1;
		vars.i++;
	}
	vars.tmp = vars.i;
	if (is_it_alpha(str, &vars.i) || !(str[vars.tmp] >= '0'
			&& str[vars.tmp] <= '9'))
		else_of_atoi(&list, two_d, args);
	while (str[vars.tmp] >= '0' && str[vars.tmp] <= '9')
	{
		vars.result = vars.result * 10 + str[vars.tmp] - 48;
		check_int_overflow(vars.result * vars.signe, list, two_d, args);
		vars.tmp++;
	}
	return ((int)(vars.result * vars.signe));
}
