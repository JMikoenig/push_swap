/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_specific_sizes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:27:55 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/09 11:15:01 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

static void	sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		swap_a(*a);
	return ;
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

	highest = find_highest(*a, 3);
	if (*a == highest)
		rotate_a(a);
	if ((*a)->next == highest)
		rev_rotate_a(a);
	if ((*a)->value > (*a)->next->value)
		swap_a(*a);
	return ;
}

void	short_sort(t_node **a, int size)
{
	if (size == 1)
		return ;
	if (size == 2)
		sort_two(a);
	if (size == 3)
		sort_three(a);
	// if (size == 4)
	// 	sort_four();
	// if (size == 5)
	// 	sort_five();
}
