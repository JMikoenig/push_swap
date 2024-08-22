/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:52:54 by jamanzan          #+#    #+#             */
/*   Updated: 2024/07/16 16:51:59 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

static int	str_separate(char *srcstr, char sep, char ***output)
{
	int		i;
	int		len;
	int		numparts;
	char	**currentpart;

	i = 0;
	len = ft_strlen(srcstr);
	numparts = 0;
	while (i < len)
	{
		if (srcstr[i] == sep)
		{
			srcstr[i] = '\0';
			numparts++;
		}
		i++;
	}
	numparts++;
	*output = malloc(numparts * sizeof(char *));
	if (!(*output))
	{
		// free(output);
		exit(1);
	}
	currentpart = *output;
	*currentpart = srcstr;
	i = 0;
	while (i < len)
	{
		if (srcstr[i] == '\0')
		{
			while (srcstr[i + 1] == '\0')
			{
				i++;
				numparts--;
			}
			currentpart++;
			*currentpart = &(srcstr[i + 1]);
		}
		i++;
	}
	return (numparts);
}

int parse_input_array(int argc, char** argv, int** output_int_arr) {
	int size;
	char** tokens;
	tokens = NULL;
	if(argc == 2) {
		size = str_separate(argv[1], ' ', &tokens);
	} else {
		tokens = argv + 1;
		size = argc - 1;
	}
	*output_int_arr = arr_atoi(tokens, size);
	return size;
}
