/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:44:00 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/10 14:52:25 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_node
{
	int				value;
	int				pos;
	int				above_median;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// input_parsing.c
int		parse_input_array(int argc, char **argv, int **output_int_arr);

// utils.c
int		*arr_atoi(char **tokens, int size);
t_node	*find_highest(t_node *lst, int size);
void	ft_print(const char *str);

// checks.c
int		check_overflow(long n);
int		check_syntax(const char *n);

// str_utils.c
int		str_separate(char *srcstr, char sep, char ***output);

// initialize.c
int		initialize(t_node **head, int *arr, const int size);

// input_validation.c
int		enough_arguments(int argc, char **argv);
int		has_duplicates(const int *int_arr, const int size);
int		is_sorted(const int *arr, const int size);

// stack_sorter.c
void	sort(int *input_arr, int size);

// node_management.c
t_node	*create_node(int value);
void	set_nodes(t_node *a, int size_a, t_node *b, int size_b);
void	set_target(t_node *src, int size_src, t_node *dst, int size_dst);
void	set_position(t_node *lst, int size);
void	free_stack(t_node *head);

// sort_short.c
void	sort_three(t_node **a);
void	short_sort(t_node **a, int size);


// === OPERATIONS ===

void	push_a(t_node **stack_a, int *size_a, t_node **stack_b, int *size_b);
void	push_b(t_node **stack_a, int *size_a, t_node **stack_b, int *size_b);

void	rotate_a(t_node **head);
void	rotate_b(t_node **head);
void	double_rotate(t_node **head_a, t_node **head_b);

void	rev_rotate_a(t_node **head);
void	rev_rotate_b(t_node **head);
void	double_rev_rotate(t_node **head_a, t_node **head_b);

void	swap_a(t_node *current);
void	swap_b(t_node *current);
void	double_swap(t_node *a, t_node *b);
