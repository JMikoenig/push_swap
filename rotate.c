#include "push_swap.h"
#include <stdio.h>

void	rotate(Node **head)
{
	*head = (*head)->next;
}

void	rev_rotate(Node **head)
{
	*head = (*head)->prev;
}

void	double_rotate(Node **head_a, Node **head_b)
{
	rotate(head_a);
	rotate(head_b);
}

void	double_rev_rotate(Node **head_a, Node **head_b)
{
	rev_rotate(head_a);
	rev_rotate(head_b);
}
