#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv) 
{
	int		size;
	int		*arrayToSort;
	char	**tokens = NULL;
	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;
	
	if (argc == 1)
	{
		return (1);
	}
	else if (argc == 2)
	{
		if (!argv[1][0])
			return (1);
		else
			size = str_separate(argv[1], ' ', &tokens);
	}
	else
	{
		tokens = argv + 1;
		size = argc - 1;
	}
	printf("The tokens are:\n");
	printStrList(tokens, size);
	arrayToSort = arr_atoi(tokens, size);
	printf("The final array is:\n");
	printIntList(arrayToSort, size);
	if (has_repetitions(arrayToSort, size))
	{
		printf("Duplicates detected!\n");
		return (2);
	}
	initialize(&stack_a, arrayToSort, size);
	printf("The initialized stack A is:\n");
	printList(stack_a, size);
	push(&stack_a, &stack_b);
	printf("A ");
	printList(stack_a, --size);
	printf("B ");
	printList(stack_b, 1);
	push(&stack_a, &stack_b);
	printf("A ");
	printList(stack_a, --size);
	printf("B ");
	printList(stack_b, 2);
	push(&stack_a, &stack_b);
	printf("A ");
	printList(stack_a, --size);
	printf("B ");
	printList(stack_b, 3);



	/*
	int status = validate_input(argc, argv);
	if (status) {
		// Imprimir error
		return status;
	}
	// Decidir si usar directamente los argv o si hay que parsear primero
	if (queremos parsear) {
			char **tokens = NULL;
			int size = split(argv[1], ' ', tokens);
			convert(tokens, arrayToSort, size)
	} else {
		convert(argv + 1. arrayToSort, argc - 1);
	}
	int areThereDuplicates = checkDuplicates(arrayToSort);
	if (areThereDuplicates) {
				// Imprimir error
		return 1;
	}
	t_node* stack_a;
	t_node* stack_b;
	initialize(stack_a, arrayToSort, size);

	*/

}