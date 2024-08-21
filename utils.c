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
