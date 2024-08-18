#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int			value;
	int			pos;
	int		above_median;
	struct node	*target;
	struct node	*next;
	struct node	*prev;
}				Node;


Node* createNode(int value) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->value = value;
    return node;
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



int main() 
{
    int arr[] = {1,2,3};
    int size = 3;

    
    Node* head = createNode(arr[0]);
    Node* current = head; 

    for(int i = 1; i<size; i++) {
        Node* node = createNode(arr[i]);
        node->prev = current;
        current-> next = node;
        current = current->next;
    }

    current->next = head;

    printList(head, size);
}