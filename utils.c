/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:38:24 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/04 00:49:45 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	return (node);
}

int	ft_atoi(char *str)
{
	int		pol;
	long	res;
	char	*p;

	pol = 1;
	res = 0;
	p = str;
	while (*p && (*p == '\n' || *p == '\t'
			|| *p == '\v' || *p == '\f' || *p == '\r'))
		p++;
	if (*p == '-')
		pol = -1;
	if (*p == '-' || *p == '+')
		p++;
	if (!check_syntax(p))
		return (0);
	while (*p && *p >= '0' && *p <= '9')
	{
		res = res * 10 + (*p - '0');
		p++;
	}
	if (!check_overflow(res * pol))
		return (0);
	return (res * pol);
}

int	*arr_atoi(char **tokens, int size)
{
	int	i;
	int	*nums;

	i = 0;
	nums = malloc(size * sizeof(int));
	while (i < size)
	{
		if (!ft_strncmp(tokens[i], "0", 1))
			nums[i] = 0;
		else
			if (ft_atoi(tokens[i]) == 0)
				exit(1);
		nums[i] = ft_atoi(tokens[i]);
		i++;
	}
	return (nums);
}
