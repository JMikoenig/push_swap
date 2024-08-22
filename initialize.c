#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int	initialize(Node *head, int *arr, int *size)
{
	int		i;
	Node	*head;
	Node	*current;
	Node	*new_node;

	i = 1;
	head = create_node(arr[0]);
	current = head;
	while (i < size)
	{
		new_node = create_node(arr[i]);
		new_node->prev = current;
		current->next = new_node;
		current = current->next;
		i++;
	}
	current->next = head;
	return (0);
}
