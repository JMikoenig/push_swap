#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_node	*get_selected_node(t_node *stack_a, const t_node *stack_b,  int size_a, int size_b)
{
	int		i;
	int		cost;
	int		cheapest;
	t_node	*current;
	t_node	*cheapest_node;

	i = 0;
	cost = 0;
	cheapest = INT_MAX;
	current = stack_a;
	while (i < size_a)
	{
		cost = get_cost(current, size_a, size_b);
		if (cost < cheapest)
		{
			cheapest = cost;
			cheapest_node = current;
		}
		current = current->next;
		i++;

	}
	return cheapest_node;
} 
