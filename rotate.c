#include "push_swap.h"
#include <stdio.h>

void	rotate(t_node **head)
{
	*head = (*head)->next;
}

void	rev_rotate(t_node **head)
{
	*head = (*head)->prev;
}

void	double_rotate(t_node **head_a, t_node **head_b)
{
	rotate(head_a);
	rotate(head_b);
}

void	double_rev_rotate(t_node **head_a, t_node **head_b)
{
	rev_rotate(head_a);
	rev_rotate(head_b);
}
