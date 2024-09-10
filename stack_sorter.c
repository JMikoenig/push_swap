/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:38:58 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/10 16:10:18 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *input_arr, int size)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_a;
	int		size_b;

	stack_a = NULL;
	stack_b = NULL;
	if (is_sorted(input_arr, size))
	{
		free(input_arr);
		return ;
	}
	initialize(&stack_a, input_arr, size);
	size_a = size;
	size_b = 0;
	sort(stack_a, size_a, stack_b, size_b);
}
