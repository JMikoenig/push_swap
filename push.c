#include "push_swap.h"

void	push_a(void)
{
	*a = current.next;
	current.prev.next = current.next;
	current.next.prev = current.prev;
	current.next = b_node;
	current.prev = b_node.prev;
	current.next.prev = current;
	current.prev.next = current;
	*b = current;     
}

void	push_b(void)
{
	*b = current.next;
	current.prev.next = current.next;
	current.next.prev = current.prev;
	current.next = a_node;
	current.prev = a_node.prev;
	current.next.prev = current;
	current.prev.next = current;
	*a = current;     
}