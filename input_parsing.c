/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:52:54 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/11 13:25:01 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input_array(int argc, char **argv, int **output_int_arr)
{
	int		i;
	int		size;
	char	**tokens;

	i = -1;
	tokens = NULL;
	if (argc == 2)
		size = str_separate(argv[1], ' ', &tokens);
	else
	{
		size = argc - 1;
		tokens = malloc(size * sizeof(char *));
		if (!tokens)
		{
			free(tokens);
			return (0);
		}
		while (++i < size)
			tokens[i] = argv[i + 1];
	}
	*output_int_arr = arr_atoi(tokens, size);
	free(tokens);
	return (size);
}
