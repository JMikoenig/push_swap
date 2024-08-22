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

static int	count_words(char *str, char separator)
{
	int	words;
	int	inside_word;

	words = 0;
	while (*str)
	{
		inside_word = 0;
		while (*str == separator)
			str++;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				words++;
				inside_word++;
			}
			str++;
		}
	}
	return (words);
}

static char	*get_word(char *str, char separator)
{
	static int	c = 0;
	char		*word;
	int			i;
	size_t		len;

	i = 0;
	len = 0;
	while (str[c] == separator)
		c++;
	while ((str[c + len] != separator) && str[c + len])
		len++;
	word = malloc(len + 1 * sizeof(char));
	if (!word)
	{
		free(word);
		return (NULL);
	}
	while (len--)
	{
		word[i] = str[c];
		i++;
		c++;
	}
	word[i] = '\0';
	return (word);
}

int	ft_split(char *str, char separator, char **tokens)
{
	int		i;
	int		words;
	int		count;
	char	*tmp;

	i = 0;
	words = count_words(str, separator);
	count = words;
	if (!words)
		exit(1);
	tokens = malloc(words * sizeof(char *));
	if (!tokens)
	{
		free(tokens);
		return (0);
	}
	while (count-- >= 0)
	{
		if (!i)
		{
			tokens[i] = malloc(sizeof(char));
			if (!tokens[i])
			{
				free(tokens[i]);
				return (0);
			}
			tokens[i++][0] = '\0';
			continue ;
		}
		tmp = get_word(str, separator);
		tokens[i++] = tmp;
	}
	printf("adding: %s", tokens[0]);
	exit(0);
	return (words);
}

int	str_separate(char *srcstr, char sep, char ***output)
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
		free(output);
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
	}
	return (numparts);
}
