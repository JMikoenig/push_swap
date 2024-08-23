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

	i = 1;
	cost = 0;
	printf("size_a: %d\n", size_a);
	printf("size_b: %d\n", size_b);
	cheapest = stack_a->value;
	current = stack_a;
	while (i < size_a)
	{
		current = current->next;
		// printf("get_selected_node >> get_cost >> current: %d, size_a: %d, size_b: %d\n", current->value, size_a, size_b);
		printf("get_selected_node >> get_cost >> current: %d, target: %d, size_a: %d, size_b: %d\n", current->value, current->target->value, size_a, size_b);
		cost = get_cost(current, size_a, size_b);
			current->value,
			current->pos,
			cost;
		if (cost < cheapest)
		{
			cheapest = cost;
			cheapest_node = current;
		}
		i++;

	}
	return cheapest_node;
} 