#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	check_syntax(const char *n)
{
	int	len;

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

int	check_overflow(long n)
{
	if (n > INT_MAX || n < INT_MIN)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	has_repetitions(const int *arrayToSort, const int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arrayToSort[i] == arrayToSort[j])
			{
				write(1, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
