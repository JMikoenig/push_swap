/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:38:42 by jamanzan          #+#    #+#             */
/*   Updated: 2024/08/22 18:38:43 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *current, char c)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	temp->value = current->value;
	current->value = current->next->value;
	current->next->value = temp->value;
	free(temp);
}

void	swap_both(t_node *a, t_node *b)
{
	swap(a);
	swap(b);
}
