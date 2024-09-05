/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:38:58 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/05 20:14:10 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	final_rotation(t_node **head, const int size)
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

static t_node	*select_node(const int size_a,
				t_node *stack_a, const int size_b)
{
	int		i;
	t_node	*out;
	t_node	*current;

	out = stack_a;
	current = stack_a->next;
	i = 1;
	while (i < size_a)
	{
		if (get_cost(current, size_a, size_b) < get_cost(out, size_a, size_b))
			out = current;
		current = current->next;
		i++;
	}
	return (out);
}

static void	move_on_top(t_node *node, t_node **stack_a, t_node **stack_b)
{
	while (node != *stack_b || node->target != *stack_a)
	{
		if (node != *stack_b && node->target != *stack_a) // si ninguno es la cabeza (pero y si above_median 1 y 0?)
		{
			if (node->above_median && node->target->above_median)
				double_rotate(stack_a, stack_b);
			else if (!(node->above_median) && !(node->target->above_median))
				double_rev_rotate(stack_a, stack_b);
		}
		if (node->above_median && node != *stack_b)
			rotate_b(stack_b);
		else if (!(node->above_median) && node != *stack_b)
			rev_rotate_b(stack_b);
		if (node->target->above_median && node->target != *stack_a)
			rotate_a(stack_a);
		else if (!(node->target->above_median) && node->target != *stack_b)
			rev_rotate_a(stack_a);
		// printf("=== unexpected state info ===\n"); //////////////////////////////////////////////////
		// printf("node: %d\n", node->value); //////////////////////////////////////////////////
		// printf("node target: %d\n", node->target->value); //////////////////////////////////////////////////
		// exit(100);
	}
	return ;
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
	push_b(&stack_a, &size_a, &stack_b, &size_b);
	push_b(&stack_a, &size_a, &stack_b, &size_b);
	//////////////////////////////////////////////////
	while (size_a > 3)
	{
		printf("=== STACK A ===\n"); //////////////////////////////////////////////////
		printList(stack_a, size_a); //////////////////////////////////////////////////
		printf("=== STACK B ===\n"); //////////////////////////////////////////////////
		printList(stack_b, size_b); //////////////////////////////////////////////////
		set_nodes(stack_a, size_a, stack_b, size_b);
		selected_node = select_node(size_a, stack_a, size_b);
		move_on_top(selected_node, &stack_b, &stack_a);
		push_b(&stack_a, &size_a, &stack_b, &size_b);
	}
	sort_three(&stack_a);
	// final_rotation(&stack_a, size_a);
	printf("========== END ==========\n"); //////////////////////////////////////////////////
	printf("=== STACK A ===\n"); //////////////////////////////////////////////////
	printList(stack_a, size_a); //////////////////////////////////////////////////
	printf("=== STACK B ===\n"); //////////////////////////////////////////////////
	printList(stack_b, size_b); //////////////////////////////////////////////////
}
