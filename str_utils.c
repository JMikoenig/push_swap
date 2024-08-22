#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
