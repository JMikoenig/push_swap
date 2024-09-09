/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:27:55 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/09 23:02:41 by jamanzan         ###   ########.fr       */
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
	return ;
}
