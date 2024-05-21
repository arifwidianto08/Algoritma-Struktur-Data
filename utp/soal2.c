#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 100

// Define your customer struct
typedef struct
{
    char name[50];
    char item[50];
    int queueNumber;
} Customer;

// Define your queue struct
typedef struct
{
    int front, rear, size;
    Customer items[QUEUE_SIZE];
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue)
{
    return queue->size == 0;
}

// Function to check if the queue is full
int isFull(Queue *queue)
{
    return queue->size == QUEUE_SIZE;
}

// Function to enqueue a customer into the queue
void enqueue(Queue *queue, Customer customer)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->items[queue->rear] = customer;
    queue->size++;
}

// Function to dequeue a customer from the queue
Customer dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        exit(1);
    }
    Customer customer = queue->items[queue->front];
    queue->front = (queue->front + 1) % QUEUE_SIZE;
    queue->size--;
    if (queue->size == 0)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    return customer;
}

// Function to peek at the front customer of the queue
Customer peek(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->items[queue->front];
}

void printTableHeader()
{
    printf("----------------------------------------------------------------------------------------\n");
    printf("Customer\t\t\tItem\t\t\tQueue Number\n");
    printf("----------------------------------------------------------------------------------------\n");
}

// Function to show all customers in the queue
void showQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    int i = queue->front;

    printTableHeader();
    while (i != (queue->rear + 1) % QUEUE_SIZE)
    {
        printf("%-*s\t%-*s\t%d\n",
               30, queue->items[i].name,
               20, queue->items[i].item,
               queue->items[i].queueNumber);
        i = (i + 1) % QUEUE_SIZE;
    };
}

int main()
{
    // Example usage
    Queue queue;
    initializeQueue(&queue);

    // Adding customers to the queue
    Customer customer1 = {"John", "Cappuccino", 1};
    Customer customer2 = {"Alice", "Aren Latte", 2};
    Customer customer3 = {"Bob", "Croissant", 3};

    enqueue(&queue, customer1);
    enqueue(&queue, customer2);
    enqueue(&queue, customer3);

    // Displaying all customers in the queue after enqueue
    printf("Queue Old State ( Antrian Awal ):\n");
    showQueue(&queue);

    printf("\n");
    printf("Finished Queue ( Antrian Diproses ):\n");
    printTableHeader();

    Customer finishedOrder1 = dequeue(&queue);
    printf("%-*s\t%-*s\t%d\n",
           30, finishedOrder1.name,
           20, finishedOrder1.item,
           finishedOrder1.queueNumber);

    Customer finishedOrder2 = dequeue(&queue);
    printf("%-*s\t%-*s\t%d\n",
           30, finishedOrder2.name,
           20, finishedOrder2.item,
           finishedOrder2.queueNumber);

    // Displaying all customers in the queue after deque
    printf("\nQueue Current State ( Antrian Saat Ini ):\n");
    showQueue(&queue);

    return 0;
}
