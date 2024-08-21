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

int	count_words(char *str, char separator)
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

char	*get_word(char *str, char separator)
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

int	ft_split(char *str, char separator, char **parsed_argv)
{
	int		i;
	int		words;

	i = 0;
	words = count_words(str, separator);
	if (!words)
		exit(1);
	parsed_argv = malloc((words + 2) * sizeof(char *));
	if (!parsed_argv)
	{
		free(parsed_argv);
		return (NULL);
	}
	while (words-- >= 0)
	{
		if (!i)
		{
			parsed_argv[i] = malloc(sizeof(char));
			if (!parsed_argv[i])
			{
				free(parsed_argv[i]);
				return (NULL);
			}
			parsed_argv[i++][0] = '\0';
			continue ;
		}
		parsed_argv[i++] = get_word(str, separator);
	}
	parsed_argv[i] = NULL;
	return (words);
}
