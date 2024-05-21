#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StringStack
{
    int top;
    int size;
    char *array;
};

struct StringStack *createStack(int size)
{
    struct StringStack *stack = (struct StringStack *)malloc(sizeof(struct StringStack));
    stack->size = size;
    stack->top = -1;
    stack->array = (char *)malloc(stack->size * sizeof(char));
    return stack;
}

int isFull(struct StringStack *stack)
{
    return stack->top == stack->size - 1;
}

int isEmpty(struct StringStack *stack)
{
    return stack->top == -1;
}

void push(struct StringStack *stack, char item)
{
    if (isFull(stack))
    {
        return;
    }

    stack->array[++stack->top] = item;
}

char pop(struct StringStack *stack)
{
    return isEmpty(stack) ? -1 : stack->array[stack->top--];
}

void reverse(char str[])
{
    int str_len = strlen(str);
    struct StringStack *stack = createStack(str_len);

    int i;
    for (i = 0; i < str_len; i++)
    {
        push(stack, str[i]);
    }

    for (i = 0; i < str_len; i++)
    {
        str[i] = pop(stack);
    }
}

// Driver program to test above functions
int main()
{
    char str[] = "Bandung";

    printf("Original String : %s\n", str);
    reverse(str);
    printf("Reversed String : %s\n\n", str);

    return 0;
}
