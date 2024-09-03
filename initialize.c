/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:42:14 by jamanzan          #+#    #+#             */
/*   Updated: 2024/08/22 18:42:14 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int	initialize(t_node **head, const int *arr, const int size)
{
	int		i;
	t_node	*current;
	t_node	*new_node;
	int sorted_arr[size];

	i = 1;
	get_sorted_arr(arr, size, sorted_arr);
	*head = create_node(arr[0]);
	(*head)-> final_index = find_index_of((*head)->value, sorted_arr, size);
	current = *head;

	while (i < size)
	{
		new_node = create_node(arr[i]);
		new_node -> final_index = find_index_of(new_node->value, sorted_arr, size);
		new_node->prev = current;
		current->next = new_node;
		current = current->next;
		i++;
	}
	current->next = *head;
	(*head)->prev = current;
	return (0);
}
