#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

void printStack(int *stack, int count, char *name)
{
    printf("Stack %s : ", name);
    if (count > 0)
    {
        printf("[ ");
        for (int i = 0; i < count; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("]");
    }
    else
    {
        printf("[] ( Empty )");
    }
}

int twoStacks(int maxSum, int *a, int a_count, int *b, int b_count)
{
    int i = 0, j = 0, sum = 0, count = 0, maxCount = 0;

    // Move pointer i to the maximum number of elements from stack a that can be included
    while (i < a_count && sum + a[i] <= maxSum)
    {
        int old_sum = sum;
        sum += a[i];
        printf("Taking value %d from Stack A\n", a[i]);
        printf("  Current sum: %d as a result from ( %d + %d )\n", sum, old_sum, a[i]); // Print the current value of sum
        i++;
        count++;
        printf("    ");
        printStack(a + i, a_count - i, "A");
        printf("\n");
    }
    printf("\n");
    maxCount = count;

    // Try including elements from stack b one by one
    while (j < b_count && i >= 0)
    {
        if (sum + b[j] <= maxSum)
        {
            int old_sum = sum;
            sum += b[j];
            printf("Taking value %d from Stack B\n", b[j]);
            printf("  Current sum: %d as a result from ( %d + %d )\n", sum, old_sum, b[j]); // Print the current value of sum
            j++;
            count++;
            maxCount = max(maxCount, count);
            printf("    ");
            printStack(b + j, b_count - j, "B");
            printf("\n");
        }
        else if (i > 0)
        {
            int old_sum = sum;
            i--;
            sum -= a[i];
            printf("Bring back value %d to Stack A\n", a[i]);
            printf("  Current sum: %d as a result from ( %d - %d )\n", sum, old_sum, a[i]); // Print the current value of sum
            count--;
            printf("    ");
            printStack(a + i, a_count - i, "A");
            printf("\n");
        }
        else
        {
            break;
        }
    }

    return maxCount;
}

int main()
{
    int g;
    printf("Enter the number of games (g): ");
    scanf("%d", &g);

    while (g--)
    {
        int n, m, maxSum;
        printf("Enter the number of integers in Stack A (n), Stack B (m), and the maximum sum allowed (maxSum): ");
        scanf("%d %d %d", &n, &m, &maxSum);

        int a[n];
        printf("Enter the integers for Stack A: ");
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int b[m];
        printf("Enter the integers for Stack B: ");
        for (int i = 0; i < m; i++)
            scanf("%d", &b[i]);

        printf("\n");
        printf("---------------------------------------------------------------\n");
        printf("Initial Stack Data : \n");
        printStack(a, n, "A");
        printf("\n");
        printStack(b, m, "B");
        printf("\n\n");
        printf("\nMaximum number of elements selected: %d\n", twoStacks(maxSum, a, n, b, m));
        printf("---------------------------------------------------------------\n");
    }

    return 0;
}
