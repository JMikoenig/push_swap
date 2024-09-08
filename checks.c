/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:36:21 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/08 15:42:37 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(const char *n)
{
	int	len;

	len = 0;
	while (*n)
	{
		if (*n < '0' || *n > '9' || len > 11)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		n++;
		len++;
	}
	return (1);
}

int	check_overflow(long n)
{
	if (n > INT_MAX || n < INT_MIN)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
