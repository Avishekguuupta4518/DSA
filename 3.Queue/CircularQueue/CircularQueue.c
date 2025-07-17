#include "stdio.h"
#include "stdbool.h"
#define MAX 5

struct CircularQueue
{
    int FRONT, REAR;
    int Data[MAX];
};

bool isFull(struct CircularQueue *Q)
{
    if ((Q->REAR + 1) % MAX == Q->FRONT)
    {
        return true;
    }
    return false;
}

bool isEmpty(struct CircularQueue *Q)
{
    if (Q->REAR == Q->FRONT)
    {
        return true;
    }
    return false;
}

void enqueue(struct CircularQueue *Q, int add)
{
    if (isFull(Q))
    {
        printf("Queue is full\n");
    }
    else
    {
        Q->Data[Q->REAR] = add;
        printf("Added %d to the queue\n", Q->Data[Q->REAR]);
        Q->REAR = (Q->REAR + 1) % MAX;
    }
}

void dequeue(struct CircularQueue *Q)
{
    if (isEmpty(Q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Removed %d from the queue\n", Q->Data[Q->FRONT]);
        Q->FRONT = (Q->FRONT + 1) % MAX;
    }
}

int main()
{
    struct CircularQueue Q;
    Q.FRONT = 0;
    Q.REAR = 0;

    enqueue(&Q, 1);
    enqueue(&Q, 2);
    enqueue(&Q, 3);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);

    return 0;
}