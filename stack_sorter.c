/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:38:58 by jamanzan          #+#    #+#             */
/*   Updated: 2024/08/31 18:38:05 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static t_node *select_node(const t_node *stack_a, const int size_a, t_node *stack_b, const int size_b)
{
	int i;
	t_node	*out;
	t_node *current;

	out = stack_b;
	current = stack_b->next;
	i=1;

	while(i < size_b)
	{
		if (get_cost(current, size_b, size_a) < get_cost(out, size_b, size_a))
			out = current;
		current = current->next;
		i++;
	}
	return (out);
}

static void move_on_top(t_node *node, t_node **stack_a, t_node **stack_b)
{
	while (node != *stack_b || node->target != *stack_a)
	{
		
		if (node != *stack_b && node->target != *stack_a)
		{
			if (node->above_median && node->target->above_median)
			{
				double_rotate(stack_a, stack_b);
			}
			else if (!(node->above_median) && !(node->target->above_median))
			{
				double_rev_rotate(stack_a, stack_b);
			}
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
	return;
}

static int	select_command(t_node *node)
{
	if (!(node->pos) && (!node->target->pos))
		return (2);
	else if (node->above_median && node->target->above_median)
		return (9);
	else if (!(node->above_median) && (!node->target->above_median))
		return (12);
	else if (node->pos)
	{
		if (node->above_median)
			return (7);
		else
			return (10);
	}
	else if (node->target->pos)
	{
		if (node->target->above_median)
			return (8);
		else
			return (11);
	}
	return (0);
}

// justo 25 lineas; si hace falta el return puede ser una funcion "print_command(command)"
// que recibe "command" como input, en base a eso imprime lo que corresponda,
// y a su vez devuelva el input tal cual

// !!! EL LIMITE ES 4 ARGUMENTOS, CREI QUE ERA 5
// static int	perform_next_command(t_node *node, t_node **stack_a,
// 	t_node **stack_b, int *size_a, int *size_b)
// {
// 	int	command;

// 	command = select_command(node);
// 	if (*size_a == 3)
// 		return (0);
// 	if (command == 2)
// 	{
// 		push(stack_a, stack_b);
// 		(*size_a)--;
// 		(*size_b)++;
// 	}
// 	else if (command == 7)
// 		rotate(stack_a);
// 	else if (command == 8)
// 		rotate(stack_b);
// 	else if (command == 9)
// 		double_rotate(stack_a, stack_b);
// 	else if (command == 10)
// 		rev_rotate(stack_a);
// 	else if (command == 11)
// 		rev_rotate(stack_b);
// 	else if (command == 12)
// 		double_rev_rotate(stack_a, stack_b);
// 	return (command);
// }

// static int	get_next_command(t_node **stack_a, t_node **stack_b,
// 	int *size_a, int *size_b)
// {
// 	if (size_b < 2)
// 	{
// 		return (PA);
// 	}
// 	t_node	*selected_node;
// 	int	command;

// 	selected_node = get_commands(*stack_a, *stack_b, *size_a, *size_b);
// 	command = perform_next_command(selected_node, stack_a, stack_b, size_a, size_b);
// 	return (command);
// }

int	sort(const int *input_arr, int size)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*selected_node;
	int		size_a;
	int		size_b;
	int		latest_command;
	int		i;
	int		*commands;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	latest_command = 1;
	if (is_sorted(input_arr, size))
		return (0);
	initialize(&stack_a, input_arr, size);
	size_a = size;
	size_b = 0;
	while (size_a > 3)
	{
		push_b(&stack_a, &size_a, &stack_b, &size_b);
	}
	sort_three(&stack_a);

	while (size_b > 0)
	{
		set_nodes(stack_b, size_b, stack_a, size_a);
		selected_node = select_node(stack_a, size_a, stack_b, size_b);
		move_on_top(selected_node, &stack_a, &stack_b);
		printf("\n========\n");
		printf("Stack A:\n");
		printList(stack_a, size_a);
		printf("Stack B:\n");
		printList(stack_b, size_b);
		push_a(&stack_a, &size_a, &stack_b, &size_b);
	}

	printList(stack_a, size_a);
	

	// while (latest_command)	// size_a > 3 y nos olvidamos de latest_command?
	// {
	// 	set_nodes(stack_a, size_a, stack_b, size_b);
	// 	latest_command = get_next_command(&stack_a, &stack_b, &size_a, &size_b);
	// 	printf("latest command: %d\n", latest_command);

	// 	printf("State after executing the command\n");
	// 	printf("Stack A\n");
	// 	printList(stack_a, size_a);
	// 	printf("Stack B\n");
	// 	printList(stack_b, size_b);
	// }

	// while(!done) {
	// 	nodo_a_posicionar = get_nextNodo()
	// 	comandosPara_posicionarNodo = getComandos(..)
	// 	while(c){

	// 	}
	// }
	// */
	// return (0);
}
