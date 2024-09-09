/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:44:55 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/09 22:36:07 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		size;
	int		*input_array;

	if (!enough_arguments(argc, argv))
		return (-1);
	size = parse_input_array(argc, argv, &input_array);
	if (has_duplicates(input_array, size))
	{
		free(input_array);
		return (2);
	}
	sort(input_array, size);
	return (0);
}
