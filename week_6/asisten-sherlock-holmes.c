#include <stdio.h>
#include <stdlib.h>

// Self-referential structure for each node
struct Node
{
    char alphabet;
    struct Node *link;
};

// Function to initialize the nodes as per provided rules
void initializeNodes(struct Node *l1, struct Node *l2, struct Node *l3, struct Node *l4, struct Node *l5,
                     struct Node *l6, struct Node *l7, struct Node *l8, struct Node *l9)
{
    l1->link = NULL;
    l1->alphabet = 'F';
    l2->link = NULL;
    l2->alphabet = 'M';
    l3->link = NULL;
    l3->alphabet = 'A';
    l4->link = NULL;
    l4->alphabet = 'I';
    l5->link = NULL;
    l5->alphabet = 'K';
    l6->link = NULL;
    l6->alphabet = 'T';
    l7->link = NULL;
    l7->alphabet = 'N';
    l8->link = NULL;
    l8->alphabet = 'O';
    l9->link = NULL;
    l9->alphabet = 'R';
}

// Function to push an item onto the stack
void push(struct Node **top, char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->alphabet = data;
    newNode->link = *top;
    *top = newNode;
}

// Function to pop an item from the stack
char pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    struct Node *temp = *top;
    char popped = temp->alphabet;
    *top = temp->link;
    free(temp);
    return popped;
}

// Function to peek the top element of the stack
char peek(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return top->alphabet;
}

// Main function
int main()
{
    // Initialize nodes as per provided rules
    struct Node l1, l2, l3, l4, l5, l6, l7, l8, l9;
    initializeNodes(&l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9);

    // Link the nodes according to the provided rules
    l1.link = &l2;
    l2.link = &l3;
    l3.link = &l4;
    l4.link = &l5;
    l5.link = &l6;
    l6.link = &l7;
    l7.link = &l8;
    l8.link = &l9;
    l9.link = &l1;

    // Print the formed word
    printf("The formed word: ");
    printf("%c%c%c%c%c%c%c%c%c%c%c\n",
           l3.link->alphabet,
           l3.link->link->link->link->alphabet,
           l3.link->link->link->link->link->link->link->alphabet,
           l3.link->link->link->link->link->alphabet,
           l3.link->link->link->link->link->link->alphabet,
           l3.link->link->link->link->link->link->link->link->alphabet,
           l3.link->link->link->link->link->link->link->link->link->alphabet,
           l3.link->link->link->alphabet,
           l3.link->alphabet,
           l3.link->link->alphabet,
           l3.alphabet);
    printf("\n");

    return 0;
}
