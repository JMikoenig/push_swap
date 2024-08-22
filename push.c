#include "push_swap.h"

void	push_a(Node **head_a, Node **head_b)
{
	Node	*current;

	current = &head_a;
	*head_a = current->next;
	current->prev->next = current->next;
	current->next->prev = current->prev;
	current->next = &head_b;
	current->prev = &head_b->prev;
	current->next->prev = current;
	current->prev->next = current;
	*head_b = current;
}

void	push_b(Node **head_a, Node **head_b)
{
	Node	*current;

	current = &head_b;
	*head_b = current->next;
	current->prev->next = current->next;
	current->next->prev = current->prev;
	current->next = &head_a;
	current->prev = &head_a->prev;
	current->next->prev = current;
	current->prev->next = current;
	*head_a = current;
}
