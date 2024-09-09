/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:52:54 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/09 22:35:18 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input_array(int argc, char **argv, int **output_int_arr)
{
	int		size;
	char	**tokens;

	tokens = NULL;
	if (argc == 2)
		size = str_separate(argv[1], ' ', &tokens);
	else
	{
		tokens = argv + 1;
		size = argc - 1;
	}
	*output_int_arr = arr_atoi(tokens, size);
	return (size);
}
