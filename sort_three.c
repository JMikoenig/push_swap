#include "push_swap.h"

t_node	*find_highest(t_node *lst)
{
	int		highest;
	t_node	*highest_node;

	if (!lst)
	{
		free(lst);
		return (NULL);
		// exit(1) ???
	}
	highest = INT_MIN;
	while (lst)
	{
		if (lst->value > highest)
		{
			highest = lst->value;
			highest_node = lst;
		}
		lst = lst->next;
	}
	return (highest_node);
}

// busca el nodo con el mayor valor
// 1. si el mayor es la cabeza, mandalo al final
	// 3 1 2 >> 1 2 3	DONE
	// 3 2 1 >> 2 1 3	ONE MORE STEP
// 2. si el mayor es el segundo nodo, mandalo al final
	// 1 3 2 >> 2 1 3	ONE MORE STEP
	// 2 3 1 >> 1 2 3	DONE
// 3. el mayor esta al final si o si; si el primero es mayor que el segundo, swap
	// 2 1 3 >> 1 2 3	DONE
void	sort_three(t_node **a)
{
	t_node	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		rotate(a);
	if ((*a)->next == highest)
		rev_rotate(a);
	if ((*a)->value > (*a)->next->value)
		swap(a);
}
