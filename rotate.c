/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:36:31 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/08 15:46:02 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **head)
{
	*head = (*head)->next;
}

void	double_rotate(t_node **head_a, t_node **head_b)
{
	ft_print("rr");
	rotate(head_a);
	rotate(head_b);
}

void	rotate_a(t_node **head)
{
	ft_print("ra");
	rotate(head);
}

void	rotate_b(t_node **head)
{
	ft_print("rb");
	rotate(head);
}
