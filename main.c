/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:00:39 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/04 22:03:31 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	is_it_space(char **str)
{
	int	i;
	int	len;
	int	check;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		check = 0;
		len = ft_strlen(str[i]);
		while (str[i][j])
		{
			if (str[i][j] == ' ')
				check++;
			j++;
		}
		if (check == len)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	check(t_stack_list **a, char **two_d, char *args)
{
	is_lst_size(a, two_d, args);
	check_is_duplicated(is_duplicated(*a), a, two_d, args);
	check_is_sorted(is_sorted(*a), a, two_d, args);
}

void	is_it_null(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0])
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char			*args;
	char			**two_d;
	t_stack_list	*a;
	t_stack_list	*b;

	if (argc <= 2)
		return (1);
	a = NULL;
	b = NULL;
	is_it_null(argv, argc);
	is_it_space(argv);
	args = join_args(argc, argv);
	two_d = split_args(args);
	create_stack_a(two_d, &a, args);
	check(&a, two_d, args);
	if (lst_size(a) <= 5)
		sort_five(&a, &b);
	else
		push_swap(&a, &b);
	free_list(a);
	ftt_free(two_d);
	free(args);
	return (0);
}
