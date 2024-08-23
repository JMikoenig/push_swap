/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamanzan <jamanzan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:42:27 by jamanzan          #+#    #+#             */
/*   Updated: 2024/08/22 18:42:28 by jamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static char** initialize_str_array(int size)
{
	char **output;

	output = malloc(size * sizeof(char *));
	if (!output)
	{
		free(output);
		exit(1);
	}
	return output;
}

int char_replace(const char old, const char new, char** str, const int len)
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
	int		i;
	int		len;
	int 	numparts;
	char	**currentpart;

	i = 0;
	len = ft_strlen(srcstr);
	numparts = char_replace(sep, '\0', &srcstr, len) + 1;
	*output = initialize_str_array(numparts);
	currentpart = *output;
	*currentpart = srcstr;
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
