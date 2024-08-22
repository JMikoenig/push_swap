/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:38:58 by jamanzan          #+#    #+#             */
/*   Updated: 2024/08/22 18:41:05 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	get_next_command(t_node **stack_a, t_node **stack_b,
	int *size_a, int *size_b)
{
	if (*size_b < 2)
	{
		push(stack_a, stack_b);
		(*size_a)--;
		(*size_b)++;
		return (2);
	}
	return (0);
}

int	sort(const int *input_arr, int size)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_a;
	int		size_b;
	int		latest_command;

	stack_a = NULL;
	stack_b = NULL;
	latest_command = 1;
	if (is_sorted(input_arr, size))
		return (0);
	initialize(&stack_a, input_arr, size);
	size_a = size;
	size_b = 0;
	while (latest_command)
	{
		latest_command = get_next_command(&stack_a, &stack_b, &size_a, &size_b);
		printf("%d", latest_command);
	}
	return (0);
}
