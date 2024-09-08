/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:38:24 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/08 15:46:57 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	if (!n)
		return (0);
	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (*us1 && (*us1 == *us2) && --n)
		if (*us1++ != *us2++)
			return (*us1 - *us2);
	return (*us1 - *us2);
}

static int	ft_atoi(char *str)
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

t_node	*find_highest(t_node *lst, int size)
{
	t_node	*highest_node;
	t_node	*current;

	if (!lst)
		return (NULL);
	current = lst;
	highest_node = current;
	while (size)
	{
		current = current->next;
		if (current->value > highest_node->value)
			highest_node = current;
		size--;
	}
	return (highest_node);
}

void	ft_print(const char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}
