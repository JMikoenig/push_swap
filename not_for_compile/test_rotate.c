#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>


Node    *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return (newNode);
}

void printList(Node *head)
{
    Node *current = head;
    printf("\nLinked List: ");

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n\n");
}

void swap(int **pa, int **pb)
{
    int *tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

int main()
{
    Node *nodea1 = createNode(1);
    Node *nodea2 = createNode(2);
    Node *nodea3 = createNode(3);
    Node *nodea4 = createNode(4);

    nodea1->next = nodea2;
    nodea2->next = nodea3;
    nodea3->next = nodea4;
    nodea4->next = nodea1;

    nodea1->prev = nodea4;
    nodea2->prev = nodea1;
    nodea3->prev = nodea2;
    nodea4->prev = nodea3;



    Node *nodeb1 = createNode(1);
    Node *nodeb2 = createNode(2);
    Node *nodeb3 = createNode(3);
    Node *nodeb4 = createNode(4);

    nodeb1->next = nodeb2;
    nodeb2->next = nodeb3;
    nodeb3->next = nodeb4;
    nodeb4->next = nodeb1;

    nodeb1->prev = nodeb4;
    nodeb2->prev = nodeb1;
    nodeb3->prev = nodeb2;
    nodeb4->prev = nodeb3;

    Node    *head_a = nodea1;
    Node    *head_b = nodeb1;


   double_rev_rotate(&head_a, &head_b);


    printList(head_a);
    printList(head_b);
    

    return (0);
}
