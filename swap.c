/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:38:42 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/09 13:59:12 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node *current)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
	{
		free(tmp);
		return ;
	}
	tmp->value = current->value;
	current->value = current->next->value;
	current->next->value = tmp->value;
	free(tmp);
}

void	double_swap(t_node *a, t_node *b)
{
	ft_print("ss");
	swap(a);
	swap(b);
}

void	swap_a(t_node *current)
{
	ft_print("sa");
	swap(current);
}

void	swap_b(t_node *current)
{
	ft_print("sb");
	swap(current);
}
