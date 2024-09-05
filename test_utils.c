/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:20:17 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/05 17:21:17 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	printList(t_node *head, int size)
{
	t_node	*current = head;
	printf("\nLinked List: ");

	for (int i = 0; i < size; i++)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n\n");
}

void	printStrList(char **list, int size) {
	if (size <= 0)
	{
		printf("Invalid size: %d", size);
		exit(1);
	}
	for (int i = 0; i < size; i++)
		printf("%s ", list[i]);
	printf("\n");
}

void	printIntList(int *arr, int size)
{
	for (int i = 0; i < size ; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
