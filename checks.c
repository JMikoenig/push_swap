#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int check_syntax(const char *n)
{
	int len;

	len = 0;
	while (*n)
	{
		if (*n < '0' || *n > '9' || len > 11)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		n++;
		len++;
	}
	return (1);
}

int check_overflow(long n)
{
	if (n > INT_MAX || n < INT_MIN)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int check_repetition(int *arrayToSort, int size)
{
	long *arr_dups;
	int i;

	arr_dups = malloc(((long)INT_MAX - INT_MIN) * sizeof(long));
	if (!arr_dups)
	{
		free(arr_dups);
		return (0);
	}
	i = 0;
	while (i < size)
	{
		if (arr_dups[arrayToSort[i]])
		{
			write(1, "Error\n", 6);
			return (0);
		}
		arr_dups[arrayToSort[i]] = 1;
	}
	free(arr_dups);
	return (1);
}