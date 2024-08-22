#include "push_swap.h"

void	push(t_node **head_src, t_node **head_dst)
{
	t_node	*current;

	current = *head_src;
	*head_src = current->next;
	current->prev->next = *head_src;
	(*head_src)->prev = current->prev;
	if (!(*head_dst))
	{
		current->next = current;
		current->prev = current;
	}
	else
	{
		current->next = *head_dst;
		current->prev = (*head_dst)->prev;
		(*head_dst)->prev = current;
		current->prev->next = current;
	}
	*head_dst = current;
}
