/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:44:00 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/05 20:26:36 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>

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
t_node	*create_node(int value);
int		*arr_atoi(char **tokens, int size);

// checks.c
int		check_overflow(long n);
int		check_syntax(const char *n);

// str_utils.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
int		str_separate(char *srcstr, char sep, char ***output);
int		char_replace(const char old, const char new, char **str, const int len);

// test_utils.c
void	printList(t_node *head, int size);
void	printStrList(char **list, int size);
void	printIntList(int *arr, int size);

// input_validation.c
int		enough_arguments(int argc, char **argv);
int		has_duplicates(const int *int_arr, const int size);
int		is_sorted(const int *arr, const int size);

// stack_sorter.c
void	sort(const int *input_arr, int size);

// set_nodes.c
void	set_nodes(t_node *a, int size_a, t_node *b, int size_b, int direction);
int		get_cost(t_node *current, int size_a, int size_b);
void	set_target(t_node *src, int size_src, t_node *dst, int size_dst, int direction);
void	set_position(t_node *lst, int size);

// sort_three.c
t_node	*find_highest(t_node *lst, int size);
void	sort_three(t_node **a);

//logic.c
int		*get_commands(t_node *stack_a, const t_node *stack_b,
			int size_a, int size_b);

//array_utils.c
void	array_sort(int arr[], const int n);
int		find_index_of(const int num, const int arr[], const int size);
void	get_sorted_arr(const int arr[], const int size, int *output);

// print_command.c
void	ft_print(const char *str);

// === OPERATIONS ===

void	push_a(t_node **stack_a, int *size_a, t_node **stack_b, int *size_b);
void	push_b(t_node **stack_a, int *size_a, t_node **stack_b, int *size_b);
void	rotate_a(t_node **head);
void	rotate_b(t_node **head);
void	rev_rotate_a(t_node **head);
void	rev_rotate_b(t_node **head);
void	double_rotate(t_node **head_a, t_node **head_b);
void	double_rev_rotate(t_node **head_a, t_node **head_b);
void	swap_a(t_node *current);
void	swap_b(t_node *current);
void	double_swap(t_node *a, t_node *b);
int		initialize(t_node **head, const int *arr, const int size);
