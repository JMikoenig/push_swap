#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		size;
	int		*input_array;

	if(!enough_arguments(argc, argv))
		return (-1);
	size = parse_input_array(argc, argv, &input_array);
	if (has_duplicates(input_array, size))
	{
		return (2);
	}
	sort(input_array, size);
	return (0);
}