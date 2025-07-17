#include <stdio.h>
#include <stdlib.h>

// Creating Node
struct Node
{
    int data;
    struct Node *next;
};

// Creating Stack
struct Stack
{
    struct Node *top;
};

typedef struct Stack ST;

// Is Empty
int isEmpty(ST *myStack)
{
    return myStack->top == NULL;
}

// Pop
int pop(ST *myStack)
{
    if (isEmpty(myStack))
    {
        printf("The Stack is Empty!\n");
        return -1; // Error value
    }

    // Remove the top element and return its data
    struct Node *temp = myStack->top;
    int popped = temp->data;
    myStack->top = temp->next;
    free(temp);
    return popped;
}

// Push
void push(ST *myStack, int element)
{
    // Create a new node and push it onto the stack
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = element;
    newNode->next = myStack->top;
    myStack->top = newNode;
    printf("%d pushed to the stack!\n", element);
}

// Peek
int peek(ST *myStack)
{
    if (isEmpty(myStack))
    {
        printf("The Stack is Empty!\n");
        return -1; // Error value
    }
    return myStack->top->data; // Return the data at the top
}

int main()
{
    // Initialize the stack
    ST *myStack = (ST *)malloc(sizeof(ST));
    if (!myStack)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    myStack->top = NULL;

    // Perform stack operations
    push(myStack, 1);
    push(myStack, 2);
    push(myStack, 3);
    push(myStack, 4);
    push(myStack, 5);

    printf("Peek: %d\n", peek(myStack));
    printf("Pop: %d\n", pop(myStack));
    printf("Peek: %d\n", peek(myStack));
    printf("Pop: %d\n", pop(myStack));
    printf("Peek: %d\n", peek(myStack));
    printf("Pop: %d\n", pop(myStack));
    printf("Peek: %d\n", peek(myStack));
    printf("Pop: %d\n", pop(myStack));
    printf("Peek: %d\n", peek(myStack));
    printf("Pop: %d\n", pop(myStack));

    // Free the stack
    free(myStack);
    return 0;
}
