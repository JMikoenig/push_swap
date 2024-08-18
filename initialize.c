#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"




int initialize(Node* head, int *arr, int *size)
{    
    Node* head = createNode(arr[0]);
    Node* current = head; 

    for(int i = 1; i<size; i++) {
        Node* node = createNode(arr[i]);
        node->prev = current;
        current-> next = node;
        current = current->next;
    }

    current->next = head;

    return 0;
}