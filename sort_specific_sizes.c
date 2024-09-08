/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_specific_sizes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:27:55 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/08 16:23:44 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		swap_a(*a);
}

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
}

void	select_algorithm(t_node **a, int size)
{
	if (size == 1)
		return ;
	if (size == 2)
		sort_two(a);
	if (size == 3)
		sort_three(a);
	// if (size == 4)
	// 	sort_four(a);
	// if (size == 5)
	// 	sort_five(a);
}
