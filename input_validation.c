#include <unistd.h>

int enough_arguments(int argc, char** argv) {
	if (argc == 1)
		return 0;
	if (argc == 2 && !argv[1][0])
		return 0;
}

int	has_duplicates(const int *arr, const int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
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

int	is_sorted(const int *arr, const int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
