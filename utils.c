#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

int	ft_atoi(char *str)
{
	int			pol;
	long		res;
	char	*p;

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
    while (i < size) {
        if (!strcmp(tokens[i], "0"))
            nums[i] = 0;
        else
            if (ft_atoi(tokens[i]) == 0)
                exit(1);
            nums[i] = ft_atoi(tokens[i]);
        i++;
    }
    return (nums);
}

void printIntList(int *arr, int size) {
    for (int i = 0; i < size ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}