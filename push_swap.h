/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:44:00 by jamanzan          #+#    #+#             */
/*   Updated: 2024/08/23 13:47:01 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STACK_A 'a'
#define STACK_B 'b'
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
void	print_command(const char *str);
t_node	*create_node(int value);
int		*arr_atoi(char **tokens, int size);

// checks.c
int		check_overflow(long n);
int		check_syntax(const char *n);

// str_utils.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
int	str_separate(char *srcstr, char sep, char ***output);

// test_utils.c
void	printList(t_node *head, int size);
void	printStrList(char **list, int size);
void	printIntList(int *arr, int size);

// input_validation.c
int		enough_arguments(int argc, char **argv);
int		has_duplicates(const int *int_arr, const int size);
int		is_sorted(const int *arr, const int size);

// stack_sorter.c
int		sort(const int *input_arr, int size);

// set_nodes.c
void	set_nodes(t_node *a, int size_a, t_node *b, int size_b);
int		get_cost(t_node *current, int size_a, int size_b);
void	set_target(t_node *a, int size_a, t_node *b, int size_b);
void	set_position(t_node *lst, int size);

// sort_three.c
t_node	*find_highest(t_node *lst, int size);
void	sort_three(t_node **a);

// === OPERATIONS ===

void	push(t_node **head_src, t_node **head_dst);
void	rotate(t_node **head);
void	rev_rotate(t_node **head);
void	swap(t_node *current);
void	double_swap(t_node *a, t_node *b);
void	double_rotate(t_node **head_a, t_node **head_b);
void	double_rev_rotate(t_node **head_a, t_node **head_b);
int		initialize(t_node **head, const int *arr, const int size);
