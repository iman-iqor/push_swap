/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:01:19 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/04 22:14:26 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "./libft/libft.h"
# include "stdio.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_list
{
	int					number;
	struct s_stack_list	*next;
}						t_stack_list;

typedef struct s_state
{
	int					i;
	int					cw;
	int					start;
	int					end;
	int					k;
	char				**two_d;
}						t_state;

typedef struct s_atoa_state
{
	int					i;
	long				result;
	int					signe;
	int					tmp;
}						t_atoa_state;

char					*ft_sstrjoin(char *save, char *buff);
char					**split_args(char *args);
char					*ft_strncopy(char *str, int start, int end);
char					*ftt_free(char **arr);
int						count_word(char *args);
int						ff_atoi(char *str, t_stack_list *list, char **two_d,
							char *args);
int						is_it_alpha(char *str, int *i);
char					*join_args(int argc, char **argv);
void					free_list(t_stack_list *head);
t_stack_list			*create_node(int number);
void					append_node(t_stack_list **head, int number);
void					print_list(t_stack_list *list);
void					else_of_atoi(t_stack_list **list, char **two_d,
							char *args);
void					check_is_sorted(int value, t_stack_list **list,
							char **two_d, char *args);
int						is_sorted(t_stack_list *list);
int						is_duplicated(t_stack_list *list);
void					check_is_duplicated(int value, t_stack_list **list,
							char **two_d, char *args);
void					sa(t_stack_list **list);
void					swap(t_stack_list **list);
void					sb(t_stack_list **stack_b);
void					ss(t_stack_list **stack_a, t_stack_list **stack_b);
void					pa(t_stack_list **dst, t_stack_list **src);
void					pb(t_stack_list **dst, t_stack_list **src);
void					r(t_stack_list **list);
void					ra(t_stack_list **a);
void					rb(t_stack_list **b);
void					rr(t_stack_list **a, t_stack_list **b);
void					rr0(t_stack_list **list);
void					rra(t_stack_list **a);
void					rrb(t_stack_list **b);
void					rrr(t_stack_list **a, t_stack_list **b);
void					create_stack_a(char **two_d, t_stack_list **list,
							char *args);
int						lst_size(t_stack_list *list);
void					is_lst_size(t_stack_list **list, char **two_d,
							char *args);
void					help_sort_five1(t_stack_list **a);
void					help_sort_five2(t_stack_list **a);
int						find_min(t_stack_list *a);
int						find_second_min(t_stack_list *a, int min);
void					sort_three(t_stack_list **a);
void					sort_five(t_stack_list **a, t_stack_list **b);
int						max_ind(t_stack_list **b);
void					push_swap(t_stack_list **a, t_stack_list **b);
int						*create_sorted_arr(t_stack_list *a);
void					sort_arr(int *arr, int len);
int						decide_chunk(int len_a);
void					incremente(int *i, int *chunk, int len);
void					check_b(t_stack_list **b);
void					push_to_b(t_stack_list **a, t_stack_list **b, int *arr,
							int len_a);
int						max_ind(t_stack_list **b);
void					push_to_a(t_stack_list **a, t_stack_list **b);
void					is_it_space(char **str);
void					is_it_null(char **argv, int argc);
void					init_vars(t_atoa_state *vars);

#endif