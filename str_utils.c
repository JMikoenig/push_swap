/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:42:27 by jamanzan          #+#    #+#             */
/*   Updated: 2024/09/09 22:45:58 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	populate_strings(char *str, const int len,
	int numparts, char ***output)
{
	char	**current_part;
	int		i;

	current_part = *output;
	*current_part = str;
	i = 0;
	while (i < len)
	{
		if (str[i] == '\0')
		{
			while (str[i + 1] == '\0')
			{
				i++;
				numparts--;
			}
			current_part++;
			*current_part = &(str[i + 1]);
		}
		i++;
	}
	return (numparts);
}

static char	**initialize_str_array(int size)
{
	char	**output;

	output = malloc(size * sizeof(char *));
	if (!output)
	{
		free(output);
		exit(1);
	}
	return (output);
}

static int	char_replace(const char old,
	const char new, char **str, const int len)
{
	int		replaced_count;
	int		i;

	i = 0;
	replaced_count = 0;
	while (i < len)
	{
		if ((*str)[i] == old)
		{
			(*str)[i] = new;
			replaced_count++;
		}
		i++;
	}
	return (replaced_count);
}

int	str_separate(char *srcstr, char sep, char ***output)
{
	int		len;
	int		numparts;

	len = ft_strlen(srcstr);
	numparts = char_replace(sep, '\0', &srcstr, len) + 1;
	*output = initialize_str_array(numparts);
	numparts = populate_strings(srcstr, len, numparts, output);
	return (numparts);
}
