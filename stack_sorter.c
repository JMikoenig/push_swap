/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:38:58 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/05 14:54:18 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
				t_node *stack_b, const int size_b)
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
	while (node != *stack_b || node->target != *stack_a)
	{
		if (node != *stack_b && node->target != *stack_a)
		{
			if (node->above_median && node->target->above_median)
				double_rotate(stack_a, stack_b);
			else if (!(node->above_median) && !(node->target->above_median))
				double_rev_rotate(stack_a, stack_b);
		}
		else if (node != *stack_b)
		{
			if (node->above_median)
				rotate_b(stack_b);
			else
				rev_rotate_b(stack_b);
		}
		else if (node->target != *stack_a)
		{
			if (node->target->above_median)
				rotate_a(stack_a);
			else
				rev_rotate_a(stack_a);
		}
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
	while (size_a > 3)
		push_b(&stack_a, &size_a, &stack_b, &size_b);
	sort_three(&stack_a);
	while (size_b > 0)
	{
		set_nodes(stack_a, size_a, stack_b, size_b);
		selected_node = select_node(size_a, stack_b, size_b);
		move_on_top(selected_node, &stack_a, &stack_b);
		push_a(&stack_a, &size_a, &stack_b, &size_b);
		printf(" - STACK A -\n"); //////////////////////////////////////////////////
		printList(stack_a, size_a); //////////////////////////////////////////////////
		printf(" - STACK B -\n"); //////////////////////////////////////////////////
		printList(stack_b, size_b); //////////////////////////////////////////////////
	}
	final_rotation(&stack_a, size_a);
	printf("\n ===== END =====\n"); //////////////////////////////////////////////////
	printList(stack_a, size_a); //////////////////////////////////////////////////
}
