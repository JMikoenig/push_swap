/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:20:09 by jamanzan          #+#    #+#             */
/*   Updated: 2024/08/23 14:05:19 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	set_position(t_node *lst, int size)
{
	int		i;
	t_node	*current;

	i = 0;
	current = lst;
	while (i < size)
	{
		current->pos = i;
		current->above_median = current->pos <= (size / 2);
		current = current->next;
		i++;
	}
}

void	set_target(t_node *a, int size_a, t_node *b, int size_b)
{
	t_node	*current_a;
	t_node	*current_b;
	int		size;

	current_a = a;
	current_b = b;
	size = size_b;
	while (size_a)
	{
		while (size_b)
		{
			if (current_a->value > current_b->value
				&& current_a->value < current_b->prev->value)
			{
				current_a->target = current_b;
				break ;
			}
			size_b--;
			current_b = current_b->next;
		}
		if (!current_a->target)
			current_a->target = find_highest(b, size);
		size_a--;
		current_a = current_a->next;
	}
	printf("set_target: %d\n", current_a->target->value);
}

int	get_cost(t_node *current, int size_a, int size_b)
{
	int	cost;
	int	dist_a;
	int	dist_b;

	cost = 0;
	if (current->above_median)
		dist_a = current->pos;
	else
		dist_a = size_a - current->pos;
	
	printf("get_cost >> target value: %d\n", current->target->value);
	printf("get_cost >> target above median: %d\n", current->target->above_median);
	if (current->target->above_median)
		dist_b = current->target->pos;
	else
		dist_b = size_b - current->target->pos;
	if (current->above_median != current->target->above_median)
		cost = dist_a + dist_b;
	else
	{
		if (dist_a > dist_b)
			cost = dist_a;
		else
			cost = dist_b;
	}
	return (cost);
}

void	set_nodes(t_node *a, int size_a, t_node *b, int size_b)
{
	set_position(a, size_a);
	set_position(b, size_b);
	set_target(a, size_a, b, size_b);
}
