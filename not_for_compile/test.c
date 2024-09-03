// #include <stdio.h>
// #include <stdlib.h>

// typedef struct s_stack_node
// {
// 	int			        value;
// 	struct s_stack_node	*next;
// 	struct s_stack_node	*prev;
// }				        node;

// int main()
// {
//     node   *node1 = (node *) malloc(sizeof(node));
//     node   *node2 = (node *) malloc(sizeof(node));
//     node   *node3 = (node *) malloc(sizeof(node));
//     node   *node4 = (node *) malloc(sizeof(node));
//     node   *current = node1;

//     node1->value = 1;
//     node1->next = node2;
//     node1->prev = NULL;

//     node1->value = 2;
//     node1->next = node3;
//     node1->prev = node1;

//     node1->value = 3;
//     node1->next = node4;
//     node1->prev = node2;

//     node1->value = 4;
//     node1->next = NULL;
//     node1->prev = node3;

//     while (current)
//     {
//         printf("%d\n", current->value);
//         current = current->next;
//     }

//     return (0);
// }


#include <stdio.h>
#include <stdlib.h>

typedef struct  Node {
    int         value;
    struct Node *next;
    struct Node *prev;
}               Node;

void    swap(Node *current)
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

Node    *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return (newNode);
}

int main()
{
    Node *node1 = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node1;

    node1->prev = node4;
    node2->prev = node1;
    node3->prev = node2;
    node4->prev = node3;

    Node    *a = node1;
    Node    *currentA = node1;

    Node *nodeA = createNode(1);
    Node *nodeB = createNode(2);
    Node *nodeC = createNode(3);
    Node *nodeD = createNode(4);

    nodeA->next = nodeB;
    nodeB->next = nodeC;
    nodeC->next = nodeD;
    nodeD->next = nodeA;

    nodeA->prev = nodeD;
    nodeB->prev = nodeA;
    nodeC->prev = nodeB;
    nodeD->prev = nodeC;

    Node    *b = nodeA;
    Node    *currentB = node1;

    printf("\nLinked List A: ");

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", currentA->value);
        currentA = currentA->next;
    }

    printf("\nLinked List B: ");

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", currentB->value);
        currentB = currentB->next;
    }
    printf("\n\n");


    // swap(a);
    swap_both(a, b);

    printf("\nLinked List A: ");

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", currentA->value);
        currentA = currentA->next;
    }

    printf("\nLinked List B: ");

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", currentB->value);
        currentB = currentB->next;
    }
    printf("\n\n");

    return (0);
}
