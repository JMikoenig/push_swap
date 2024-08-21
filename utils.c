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
	int			res;
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
	while (*p && *p >= '0' && *p <= '9')
	{
		res = res * 10 + (*p - '0');
		p++;
	}
	return (res * pol);
}
