/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:01:47 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/04 22:13:38 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_stack_list	*create_node(int number)
{
	t_stack_list	*node;

	node = malloc(sizeof(t_stack_list));
	if (!node)
	{
		ft_putstr("memory alocation", "failed\n");
		exit(1);
	}
	node->number = number;
	node->next = NULL;
	return (node);
}

void	append_node(t_stack_list **head, int number)
{
	t_stack_list	*node;
	t_stack_list	*current;

	node = create_node(number);
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = node;
}

void	print_list(t_stack_list *list)
{
	while (list)
	{
		printf("%i\n", list->number);
		list = list->next;
	}
}

void	free_list(t_stack_list *head)
{
	t_stack_list	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

char	*join_args(int argc, char **argv)
{
	int		i;
	char	*args;

	i = 1;
	args = NULL;
	while (argv[i])
	{
		args = ft_sstrjoin(args, argv[i]);
		if (i != argc - 1)
			args = ft_sstrjoin(args, " ");
		i++;
	}
	return (args);
}
