#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular doubly linked list
void insertEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (!(*head))
    {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
        return;
    }
    Node *last = (*head)->prev;
    newNode->next = *head;
    (*head)->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
}

// Function to print the list with addresses
void printList(Node *head, const char *msg)
{
    if (!head)
        return;
    Node *temp = head;
    printf("%s\n", msg);
    do
    {
        printf("Address: %p, Data: %d\n", (void *)temp, temp->data);
        temp = temp->next;
    } while (temp != head);
}

// Function to swap two nodes
void swap(Node *a, Node *b)
{
    int tempData = a->data;
    a->data = b->data;
    b->data = tempData;
}

// Function to sort the circular doubly linked list
void sortList(Node *head)
{
    if (!head)
        return;
    Node *i;
    Node *j;
    for (i = head; i->next != head; i = i->next)
    {
        for (j = i->next; j != head; j = j->next)
        {
            if (i->data > j->data)
            {
                swap(i, j);
            }
        }
    }
}

int main()
{
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    Node *head = NULL;

    printf("Enter the elements:\n");
    for (int i = 0; i < N; i++)
    {
        int data;
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("\n");
    printList(head, "Unsorted:");

    sortList(head);

    printf("\n");
    printList(head, "Sorted:");

    return 0;
}
