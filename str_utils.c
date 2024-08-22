#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void    print_command(char *str)
{
    while (*str)
        write(1, &str, 1);
    write(1, "\n", 1);
}

void printList(Node *head, int size)
{
    Node *current = head;
    printf("\nLinked List: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n\n");
}

Node* createNode(int value) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->value = value;
    return node;
}

void printStrList(char **list, int size) {
    if (size <= 0) {
        printf("Invalid size: %d", size);
        exit(1);
    }
    for(int i=0;i<size;i++) {
        printf("%s ", list[i]);
    }
    printf("\n");
}

int	ft_atoi(const char *str)
{
	int			pol;
	long		res;
	const char	*p;

	pol = 1;
	res = 0;
	p = str;
	while (*p && (*p == '\n' || *p == '\t'
			|| *p == '\v' || *p == '\f' || *p == '\r'))
		p++;
	if (*p == '-')
		pol = -1;
	if (*p == '-' || *p == '+')
		p++;
    if (!check_syntax(p))
        return (0);
	while (*p && *p >= '0' && *p <= '9')
	{
		res = res * 10 + (*p - '0');
		p++;
	}
    if (!check_overflow(res * pol))
        return (0);
	return (res * pol);
}

int *arr_atoi(char **tokens, int size)
{
    int i;
    int *nums;

    i = 0;
    nums = malloc(size * sizeof(int));
    while (i < size)
        nums[i] = ft_atoi(tokens[i]);
    return (nums);
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