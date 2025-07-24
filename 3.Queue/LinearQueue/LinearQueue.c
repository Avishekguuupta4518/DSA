#include "stdio.h"
#include "stdbool.h"
#define MAX 5
struct Queue
{
    int FRONT, REAR;
    int Data[MAX];
};

bool isFull(struct Queue *Q)
{
    if (Q->REAR == MAX - 1)
    {
        return true;
    }
    return false;
}

bool isEmpty(struct Queue *Q)
{
    if (Q->REAR < Q->FRONT)
    {
        return true;
    }
    return false;
}

void enqueue(struct Queue *Q, int add)
{
    if (isFull(Q))
    {
        printf("Queue is full\n");
    }
    else
    {
        Q->REAR++;
        Q->Data[Q->REAR] = add;
        // to view the added element from the queue
        printf("Added %d to the queue\n", Q->Data[Q->REAR]);
    }
}

void dequeue(struct Queue *Q)
{
    if (isEmpty(Q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Removed %d from the queue\n", Q->Data[Q->FRONT]);
        printf("Front value is %d\n", Q->FRONT);
        Q->FRONT++;
    }
}

void front(struct Queue *Q)
{
    if (isEmpty(Q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front element is %d\n", Q->Data[Q->FRONT]);
    }
}

int main()
{
    struct Queue Q;
    Q.FRONT = 0;
    Q.REAR = -1;
    enqueue(&Q, 1);
    enqueue(&Q, 2);
    enqueue(&Q, 3);
    dequeue(&Q);
    dequeue(&Q);
    front(&Q);
    return 0;
}