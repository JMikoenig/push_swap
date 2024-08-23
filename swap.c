/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:38:42 by jamanzan          #+#    #+#             */
/*   Updated: 2024/08/23 13:14:53 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	swap(t_node *current)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	temp->value = current->value;
	current->value = current->next->value;
	current->next->value = temp->value;
	free(temp);
}

void	double_swap(t_node *a, t_node *b)
{
	swap(a);
	swap(b);
}
