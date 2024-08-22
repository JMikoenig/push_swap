/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:36:31 by jamanzan          #+#    #+#             */
/*   Updated: 2024/08/22 18:36:31 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rotate(t_node **head)
{
	*head = (*head)->next;
}

void	rev_rotate(t_node **head)
{
	*head = (*head)->prev;
}

void	double_rotate(t_node **head_a, t_node **head_b)
{
	rotate(head_a);
	rotate(head_b);
}

void	double_rev_rotate(t_node **head_a, t_node **head_b)
{
	rev_rotate(head_a);
	rev_rotate(head_b);
}
