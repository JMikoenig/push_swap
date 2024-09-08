/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:42:14 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/08 15:40:27 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize(t_node **head, const int *arr, const int size)
{
	int		i;
	t_node	*current;
	t_node	*new_node;

	i = 1;
	*head = create_node(arr[0]);
	current = *head;
	while (i < size)
	{
		new_node = create_node(arr[i]);
		new_node->prev = current;
		current->next = new_node;
		current = current->next;
		i++;
	}
	current->next = *head;
	(*head)->prev = current;
	return (0);
}
