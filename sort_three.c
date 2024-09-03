/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:27:55 by jamanzan          #+#    #+#             */
/*   Updated: 2024/08/23 14:10:01 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

t_node	*find_highest(t_node *lst, int size)
{
	t_node	*highest_node;
	t_node	*current;

	if (!lst)
		return (NULL);
	current = lst;
	highest_node = current;
	while (size - 1)
	{
		current = current->next;
		if (current->value > highest_node -> value)
			highest_node = current;
		size--;
	}
	return (highest_node);
}

// busca el nodo con el mayor valor
// 1. si el mayor es la cabeza, mandalo al final
	// 3 1 2 >> 1 2 3	DONE
	// 3 2 1 >> 2 1 3	ONE MORE STEP
// 2. si el mayor es el segundo nodo, mandalo al final
	// 1 3 2 >> 2 1 3	ONE MORE STEP
	// 2 3 1 >> 1 2 3	DONE
// 3. el mayor esta al final si o si;
// 	si el primero es mayor que el segundo, swap()
	// 2 1 3 >> 1 2 3	DONE
void	sort_three(t_node **a)
{
	printf("Starting sort three:\n");
	printList(*a, 3);
	t_node	*highest;

	highest = find_highest(*a, 3);
	if (*a == highest)
		rotate_a(a);
	if ((*a)->next == highest)
		rev_rotate_a(a);
	if ((*a)->value > (*a)->next->value)
		swap_a(*a);
	printf("Ending sort three:\n");
	printList(*a, 3);
}
