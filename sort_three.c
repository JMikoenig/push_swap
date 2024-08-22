/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:27:55 by jamanzan          #+#    #+#             */
/*   Updated: 2024/08/22 18:35:53 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_highest(t_node **a)
{
	int		highest;
	t_node	*highest_node;
	t_node	*current;

	if (!a)
	{
		free(a);
		return (NULL);
	}
	highest = INT_MIN;
	current = *a;
	while (a)
	{
		if (current->value > highest)
		{
			highest = current->value;
			highest_node = current;
		}
		current = current->next;
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
	t_node	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		rotate(a);
	if ((*a)->next == highest)
		rev_rotate(a);
	if ((*a)->value > (*a)->next->value)
		swap(a);
}
