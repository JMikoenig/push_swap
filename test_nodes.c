#include "push_swap.h"
#include <stdio.h>

int	main()
{
	t_node	*a;
	t_node	*b;
	t_node	*current_a;
	t_node	*current_b;
	int		size_a = 5;
	int		size_b = 3;

	t_node	*node1 = create_node(10);
	t_node	*node2 = create_node(20);
	t_node	*node3 = create_node(30);
	t_node	*node4 = create_node(40);
	t_node	*node5 = create_node(50);

	t_node	*node6 = create_node(60);
	t_node	*node7 = create_node(70);
	t_node	*node8 = create_node(80);
	
	a = node1;
	b = node6;
	current_a = a;
	current_b = b;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node1;

	node1->prev = node5;
	node2->prev = node1;
	node3->prev = node2;
	node4->prev = node3;
	node5->prev = node4;

	node6->next = node7;
	node7->next = node8;
	node8->next = node6;

	node6->prev = node8;
	node7->prev = node6;
	node8->prev = node7;

	// printf("\nsize_a: %d\n", size_a);
	// printf("%d ", node1->value);
	// printf("%d ", node2->value);
	// printf("%d ", node3->value);
	// printf("%d ", node4->value);
	// printf("%d ", node5->value);
	// printf("\nsize_b: %d\n", size_b);
	// printf("%d ", node6->value);
	// printf("%d ", node7->value);
	// printf("%d ", node8->value);
	// printf("\n\n");

	set_nodes(a, size_a, b, size_b);

	// printf("\n\n== STACK A NODES ==\n");
	// for (int i = 0; i < size_a; i++)
	// {
	// 	printf("value: %d, pos: %d, above median: %d, target: %d\n",
	// 		current_a->value,
	// 		current_a->pos,
	// 		current_a->above_median,
	// 		current_a->target->value);
	// 	current_a = current_a->next;
	// }

	// printf("\n\n== STACK B NODES ==\n");
	// for (int i = 0; i < size_b; i++)
	// {
	// 	printf("value: %d, pos: %d, above median: %d\n",
	// 		current_b->value,
	// 		current_b->pos,
	// 		current_b->above_median);
	// 	current_b = current_b->next;
	// }
	// printf("\n\n");

	
	// printf("\n\n== STACK A NODES ==\n");
	// for (int i = 0; i < size_a; i++)
	// {
	// 	printf("value: %d, pos: %d, above median: %d, target: %d\n",
	// 		current_a->value,
	// 		current_a->pos,
	// 		current_a->above_median,
	// 		current_a->target->value);
	// 	current_a = current_a->next;
	// }
	// rotate(&a);
	// current_a = a;
	// printf("\n\n== STACK A NODES ==\n");
	// for (int i = 0; i < size_a; i++)
	// {
	// 	printf("value: %d, pos: %d, above median: %d, target: %d\n",
	// 		current_a->value,
	// 		current_a->pos,
	// 		current_a->above_median,
	// 		current_a->target->value);
	// 	current_a = current_a->next;
	// }

	printf("\n\n");
	t_node	*highest = find_highest(b, size_b);
	printf("value: %d, pos: %d, above median: %d\n",
		highest->value,
		highest->pos,
		highest->above_median);

	return (0);
}