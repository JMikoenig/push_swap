/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:38:58 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/08 16:49:09 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_rotation(t_node **head, const int size)
{
	t_node	*highest_node;

	highest_node = find_highest(*head, size);
	set_position(*head, size);
	while (highest_node->next != *head)
	{
		if (highest_node->next->above_median)
			rotate_a(head);
		if (!(highest_node->next->above_median))
			rev_rotate_a(head);
	}
}

static int	get_cost(t_node *current, int size_src, int size_dst)
{
	int	cost;
	int	dist_src;
	int	dist_dst;

	cost = 0;
	if (current->above_median)
		dist_src = current->pos;
	else
		dist_src = size_src - current->pos;
	if (current->target->above_median)
		dist_dst = current->target->pos;
	else
		dist_dst = size_dst - current->target->pos;
	if (current->above_median != current->target->above_median)
		cost = dist_src + dist_dst;
	else
	{
		if (dist_src > dist_dst)
			cost = dist_src;
		else
			cost = dist_dst;
	}
	return (cost);
}

static t_node	*select_node(t_node *stack_b,
	const int size_a, const int size_b)
{
	int		i;
	t_node	*out;
	t_node	*current;

	out = stack_b;
	current = stack_b->next;
	i = 1;
	while (i < size_b)
	{
		if (get_cost(current, size_b, size_a) < get_cost(out, size_b, size_a))
			out = current;
		current = current->next;
		i++;
	}
	return (out);
}

static void	move_on_top(t_node *node, t_node **stack_a, t_node **stack_b)
{
	if (node->above_median && node->target->above_median)
		while (node->target != *stack_a && node != *stack_b)
			double_rotate(stack_a, stack_b);
	else if (!(node->above_median) && !(node->target->above_median))
		while (node->target != *stack_a && node != *stack_b)
			double_rev_rotate(stack_a, stack_b);
	while (*stack_b != node)
	{
		if (node->above_median)
			rotate_b(stack_b);
		else
			rev_rotate_b(stack_b);
	}
	while (*stack_a != node->target)
	{
		if (node->target->above_median)
			rotate_a(stack_a);
		else
			rev_rotate_a(stack_a);
	}
}

void	sort(const int *input_arr, int size)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*selected_node;
	int		size_a;
	int		size_b;

	stack_a = NULL;
	stack_b = NULL;
	if (is_sorted(input_arr, size))
		return ;
	initialize(&stack_a, input_arr, size);
	size_a = size;
	size_b = 0;
	while (size_a > 3)
		push_b(&stack_a, &size_a, &stack_b, &size_b);
	sort_three(&stack_a); // sort_specific_size(int size) >> este parametro redirecciona a la funcion apropiada
	while (size_b > 0)
	{
		set_nodes(stack_a, size_a, stack_b, size_b);
		selected_node = select_node(stack_b, size_a, size_b);
		move_on_top(selected_node, &stack_a, &stack_b);
		push_a(&stack_a, &size_a, &stack_b, &size_b);
	}
	final_rotation(&stack_a, size_a);
	free_stacks(stack_a, stack_b);
}
