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
	int	i;
	int	words;
	int	count;

	i = 0;
	words = count_words(str, separator);
	count = words;
	if (!words)
		exit(1);
	tokens = malloc(words * sizeof(char *));
	if (!tokens)
	{
		free(tokens);
		return 0;
	}
	while (count-- >= 0)
	{
		if (!i)
		{
			tokens[i] = malloc(sizeof(char));
			if (!tokens[i])
			{
				free(tokens[i]);
				return 0;
			}
			tokens[i++][0] = '\0';
			continue ;
		}
		char * tmp = get_word(str, separator);
		tokens[i++] = tmp;
	}
	printf("adding: %s", tokens[0]);
	exit(0);

	return (words);
}

int str_separate(char *srcstr, char sep, char ***output)
{
	/* Assume we have a properly NULL-terminated string. */
	int len = strlen(srcstr);

	/* Initialize the number of tokens to 0. */ 
	int numparts = 0;

	/* A temporary pointer to a char pointer we'll use later. */
	char **currentpart;
	
	/* 
	 * Replace every instance of sep with a NULL character. 
	 * This has the effect of turning one string into many; you can
	 * think of the first string beginning where the original string
	 * did, and ending at the first NULL, then the second string
	 * beginning at the character right after that NULL.
	 */
	int i;
	for (i = 0; i < len; i++)
	{
		if (srcstr[i] == sep)
		{
			srcstr[i] = '\0';	
			numparts++;
		}
	}

	/* 
	 * Increment numparts one more time, for the last substring. 
	 * i.e. if we found N separators we have N+1 parts. If two
	 * separator characters appear together, or there is a 
	 * separator at the end, then some of these become the empty
	 * string "".
	 */
	numparts++;
	
	/* Allocate space for our pointers to the various substrings
	 * Note that here we dereference output once, to assign to the
	 * char ** we declared in the calling function (i.e. main())
	 */
	*output = malloc(numparts * sizeof(char *));

	/* You should always check the return value of malloc! */
	if (*output == NULL)
	{
		perror("malloc() call in str_separate");
		exit(1);
	}
	
	/* Start with currentpart pointing to the first allocated pointer.
	 * We'll use this to step through the array of char * pointers.
	 */
	currentpart = *output;

	/*
	 * The first char * pointer should point to the beginning of the 
	 * original string, as that is necessarily the first token.
	 */
	*currentpart = srcstr;
	
	/* 
	 * We've placed \0's in the place of every occurrence of sep; so
	 * a new token/substring begins at the character AFTER a \0
	 * (excluding the very last \0, which we will never hit with this
	 * loop).
	 * 
	 * This loop finds all the NULLs we placed in the string, and stores
	 * a pointer to the character after each NULL in *currentpart, after
	 * incrementing currentpart to move to the next char * slot.
	 */
	
	for (i = 0; i < len; i++) /* < len: we never get to the last '\0', 
	                           * since strlen gives us the length of
	                           * the string, not including the NULL */
	{
		if (srcstr[i] == '\0') {
			            while(srcstr[i+1] == '\0') {
                i++;
                numparts --;
            }
			currentpart++;
			*currentpart = &(srcstr[i+1]);
		}
	}
	
	/* 
	 * We only return the integer numparts, but in fact we are 
	 * "implicitly returning" the contents of *output, since this
	 * was declared outside str_separate but modified by it.
	 */
	return numparts; 
}

