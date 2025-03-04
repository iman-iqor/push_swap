/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:02:05 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/04 22:10:11 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	lst_size(t_stack_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	is_lst_size(t_stack_list **list, char **two_d, char *args)
{
	if (lst_size(*list) == 1)
	{
		free_list(*list);
		ftt_free(two_d);
		free(args);
		exit(1);
	}
}

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
