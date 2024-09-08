/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:20:09 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/08 17:10:38 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	return (node);
}

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
			size_dst--;
			if (current_src->value > current_dst->value
				&& current_src->value < current_dst->next->value)
			{
				current_src->target = current_dst->next;
				break ;
			}
			current_dst = current_dst->next;
		}
		size_src--;
		current_src = current_src->next;
	}
}

void	set_nodes(t_node *a, int size_a, t_node *b, int size_b)
{
	set_position(a, size_a);
	set_position(b, size_b);
	set_target(b, size_b, a, size_a);
}

void	free_stacks(t_node *a, t_node *b)
{
	t_node	*current;

	current = a->next;
	while (current->next != NULL)
	{
		free(current->prev);
		current = current->next;
	}
	current = b->next;
	while (current->next != NULL)
	{
		free(current->prev);
		current = current->next;
	}
}
