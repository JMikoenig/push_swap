#include "push_swap.h"

void	swap(t_node *current, char c)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	temp->value = current->value;
	current->value = current->next->value;
	current->next->value = temp->value;
	free(temp);
}

void	swap_both(t_node *a, t_node *b)
{
	swap(a);
	swap(b);
}
