/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:06:07 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/04 01:07:53 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_index_of(const int num, const int arr[], const int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

static void	swap_indexes(int arr[], const int i, const int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void	array_sort(int arr[], const int size)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		swapped = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap_indexes(arr, j, j + 1);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
		j = 0;
	}
}

void	get_sorted_arr(const int arr[], const int size, int *output)
{
	int	i;

	i = 0;
	while (i < size)
	{
		output[i] = arr[i];
		i++;
	}
	array_sort(output, size);
}
