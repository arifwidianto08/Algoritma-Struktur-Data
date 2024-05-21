#include <stdio.h>

#define MAX_STACK_SIZE 100 // Maximum number of elements the stack can hold
typedef struct
{
    int items[MAX_STACK_SIZE];
    int top;
} Stack;

// Procedure to initialize the stack
void initializeStack(Stack *stack)
{
    stack->top = -1; // Set top to -1 to indicate an empty stack
}

// Procedure to push an element onto the stack
void push(Stack *stack, int element)
{
    if (stack->top == MAX_STACK_SIZE - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    // Increment top and add the element
    stack->top++;
    stack->items[stack->top] = element;
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    int poppedElement;
    if (stack->top == -1)
    {
        printf("Stack underflow!\n");
        return poppedElement;
    }
    // Retrieve the topmost element and decrement top
    poppedElement = stack->items[stack->top];

    stack->top--;
    return poppedElement;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) { return stack->top == -1; }

// Function to check if the stack is full
int isFull(Stack *stack) { return stack->top == MAX_STACK_SIZE - 1; }

// Procedure to peek at the topmost element of the stack
void peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", stack->items[stack->top]);
}

// Main function for testing
int main()
{
    Stack myStack;
    initializeStack(&myStack);
    // 1. Push int 1
    int int1 = 30;
    push(&myStack, int1);

    // 2. Push int 2
    int int2 = 25;
    push(&myStack, int2);

    // 3. Push int 3
    int int3 = 25;
    push(&myStack, int3);

    // 4. Peek stack
    peek(&myStack);

    // 5. Pop stack
    int popped1 = pop(&myStack);

    // 6. Print data from popped element
    printf("Popped element: %d\n", popped1);

    // 7. Pop stack
    int popped2 = pop(&myStack);

    // 8. Print data from popped element
    printf("Popped element: %d\n", popped2);

    // 9. Pop stack
    int popped3 = pop(&myStack);

    // 10. Print data from popped element
    printf("Popped element: %d\n", popped3);

    // 11. Pop stack
    int popped4 = pop(&myStack);
    printf("\n");

    // Since the stack is empty, no need to print popped data
    return 0;
}