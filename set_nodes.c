/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:20:09 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/04 00:40:11 by jamanzan         ###   ########.fr       */
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

void	set_target(t_node *src, int size_src, t_node *dst, int size_dst)
{
	t_node	*current_src;
	t_node	*current_dst;
	int		size;

	current_src = src;
	current_dst = dst;
	size = size_dst;
	while (size_src)
	{
		while (size_dst)
		{
			if (current_src->value > current_dst->value
				&& current_src->value < current_dst->next->value)
			{
				current_src->target = current_dst->next;
				break ;
			}
			size_dst--;
			current_dst = current_dst->next;
		}
		if (!current_src->target)
			current_src->target = find_highest(dst, size)->next;
		size_src--;
		current_src = current_src->next;
	}
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
