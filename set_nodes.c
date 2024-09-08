/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:20:09 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/08 14:08:06 by jamanzan         ###   ########.fr       */
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
		current_src->target = find_highest(dst, size)->next;
		size_dst = size;
		while (size_dst)
		{
			if (current_src->value > current_dst->value
				&& current_src->value < current_dst->next->value)
				{
					current_src->target = current_dst->next;
					size_dst--;
					break ;
				}
			size_dst--;
			current_dst = current_dst->next;
		}
		// printf("node: %d, p: %d, a: %d || t: %d, tp: %d, ta: %d\n", current_src->value, current_src->pos, current_src->above_median, current_src->target->value, current_src->target->pos, current_src->target->above_median); //////////////////////////////////////////////////
		size_src--;
		current_src = current_src->next;
	}
}

int	get_cost(t_node *current, int size_src, int size_dst)
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
	// printf("node: %d, cost: %d\n", current->value, cost); //////////////////////////////////////////////////
	return (cost);
}

void	set_nodes(t_node *a, int size_a, t_node *b, int size_b)
{
	set_position(a, size_a);
	set_position(b, size_b);
	set_target(b, size_b, a, size_a);
}
