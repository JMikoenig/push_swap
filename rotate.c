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

static void	rotate(t_node **head)
{
	*head = (*head)->next;
}

static void	rev_rotate(t_node **head)
{
	*head = (*head)->prev;
}

void	double_rotate(t_node **head_a, t_node **head_b)
{
	ft_print("rr");
	rotate(head_a);
	rotate(head_b);
}

void	double_rev_rotate(t_node **head_a, t_node **head_b)
{
	ft_print("rrr");
	rev_rotate(head_a);
	rev_rotate(head_b);
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

void	rev_rotate_a(t_node **head)
{
	ft_print("rra");
	rev_rotate(head);
}

void	rev_rotate_b(t_node **head)
{
	ft_print("rrb");
	rev_rotate(head);
}


