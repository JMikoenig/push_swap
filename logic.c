#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static void add_command(int ***commands, int curr_pos, int command) {
	*commands[curr_pos] = (int*) malloc(sizeof(int *));
	if (*commands[curr_pos] == NULL) {
		free(*commands[curr_pos]);
		return;
	}
	**commands[curr_pos] = command;
}

static int	**get_commands_internal(t_node *node)
{
	int **commands;
	int curr_pos;

	curr_pos=0;

	while (1)
	{
		if (!(node->pos) && (!node->target->pos))
		{
			printf("1");
			add_command(&commands, curr_pos, PA);
			curr_pos ++;
			add_command(&commands, curr_pos, NO_ACTION);
			return commands;
		}

		else if (node->above_median && node->target->above_median) {
						printf("2");
			add_command(&commands, curr_pos, RR);
			curr_pos ++;
		}

		else if (!(node->above_median) && (!node->target->above_median)) {
						printf("3");
			add_command(&commands, curr_pos, RRR);
			curr_pos ++;
		}

		else if (node->pos)
		{
						printf("4");
			if (node->above_median)
				add_command(&commands, curr_pos, RA);
			else
				add_command(&commands, curr_pos, RRA);
			curr_pos ++;
		}
		else if (node->target->pos)
		{
						printf("5");
			if (node->target->above_median)
				add_command(&commands, curr_pos, RB);
			else
				add_command(&commands, curr_pos, RRB);
			curr_pos ++;
		}
		return (NO_ACTION);
	}

	
}

int	*get_commands(t_node *stack_a, const t_node *stack_b,  int size_a, int size_b)
{
	int		i;
	int		cost;
	int		cheapest;
	t_node	*current;
	t_node	*cheapest_node;
	int* ret;

	i = 0;
	cost = 0;
	cheapest = INT_MAX;
	current = stack_a;
	if (size_b < 2) {
		ret = (int *) malloc(2*sizeof(int));
		*ret = PA;
		*(ret+1) = PA;
		return ret;
	}
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
					printf("aaaa");
	}
	return *(get_commands_internal(cheapest_node));
} 

