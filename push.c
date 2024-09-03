/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:36:10 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/04 00:56:03 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **head_src, t_node **head_dst)
{
	t_node	*current;

	current = *head_src;
	*head_src = current->next;
	current->prev->next = *head_src;
	(*head_src)->prev = current->prev;
	if (!(*head_dst))
	{
		current->next = current;
		current->prev = current;
	}
	else
	{
		current->next = *head_dst;
		current->prev = (*head_dst)->prev;
		(*head_dst)->prev = current;
		current->prev->next = current;
	}
	*head_dst = current;
}

void	push_a(t_node **stack_a, int *size_a, t_node **stack_b, int *size_b)
{
	ft_print("pa");
	push(stack_b, stack_a);
	(*size_a)++;
	(*size_b)--;
}

void	push_b(t_node **stack_a, int *size_a, t_node **stack_b, int *size_b)
{
	ft_print("pb");
	push(stack_a, stack_b);
	(*size_b)++;
	(*size_a)--;
}
