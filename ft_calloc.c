#include "push_swap.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*head;
	void	*p;

	head = malloc(count * size);
	*p = head;
	if (!p)
	{
		free (p);
		return (p);
	}
	while (size)
	{
		*p = 0;
		p++;
		size--;
	}
	return (p);
}