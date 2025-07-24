#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue node
struct Node
{
    int data;
    struct Node *next;
};

// Define the structure of the queue
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    if (!queue)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return queue->front == NULL;
}

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = createNode(data);

    // If the queue is empty, set both front and rear to the new node
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
        printf("%d enqueued to queue.\n", data);
        return;
    }

    // Otherwise, add the new node at the end of the queue and update rear
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("%d enqueued to queue.\n", data);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue underflow. Cannot dequeue.\n");
        return -1;
    }

    // Remove the front node
    struct Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    // If the queue becomes empty, set rear to NULL
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Function to peek the front element of the queue
int peek(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }
    return queue->front->data;
}

// Function to display the elements of the queue
void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main()
{
    struct Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    display(queue);

    printf("Front element is %d\n", peek(queue));

    printf("Dequeued element is %d\n", dequeue(queue));
    display(queue);

    printf("Dequeued element is %d\n", dequeue(queue));
    printf("Dequeued element is %d\n", dequeue(queue));
    display(queue);

    return 0;
}
