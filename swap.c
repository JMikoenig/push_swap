#include "push_swap.h"

void    swap(Node *current, char c)
{
    Node    *temp = (Node *)malloc(sizeof(Node));

    temp->value = current->value;
    current->value = current->next->value;
    current->next->value = temp->value;
    free(temp);
}

void    swap_both(Node *a, Node *b)
{
    swap(a);
    swap(b);
}


void    rotate();
void    rev_rotate();