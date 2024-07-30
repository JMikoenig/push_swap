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
	word = malloc(len * sizeof(char) + 1);
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

char	**ft_split(char *str, char separator)
{
	char	**str_arr;
	int		i;
	int		words;

	i = 0;
	words = count_words(str, separator);
	if (!words)
		exit(1);
	str_arr = malloc((words + 2) * sizeof(char *));
	if (!str_arr)
	{
		free(str_arr);
		return (NULL);
	}
	while (words-- >= 0)
	{
		if (!i)
		{
			str_arr[i] = malloc(sizeof(char));
			if (!str_arr[i])
			{
				free(str_arr[i]);
				return (NULL);
			}
			str_arr[i++][0] = '\0';
			continue ;
		}
		str_arr[i++] = get_word(str, separator);
	}
	str_arr[i] = NULL;
	return (str_arr);
}
