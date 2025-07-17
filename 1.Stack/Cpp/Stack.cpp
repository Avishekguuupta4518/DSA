#include <iostream>
#define MAX 5

struct Stack
{
    int TOS;       // Top of Stack index
    int DATA[MAX]; // Array to store stack elements
};

typedef struct Stack St;

// Is Empty
int isEmpty(St *myStack)
{
    return myStack->TOS == -1; // 1 if empty, 0 otherwise
}

// Is Full
int isFull(St *myStack)
{
    return myStack->TOS == MAX - 1; // 1 if full, 0 otherwise
}

// Push
void push(St *myStack, int element)
{
    if (isFull(myStack))
    {
        std::cout << "Stack is Full!" << std::endl;
    }
    else
    {
        myStack->TOS++;
        myStack->DATA[myStack->TOS] = element;
        std::cout << element << " pushed to the stack!" << std::endl;
    }
}

// Peek
int peek(St *myStack)
{
    if (isEmpty(myStack))
    {
        std::cout << "The Stack is Empty!" << std::endl;
        return -1; // Error value
    }
    else
    {
        return myStack->DATA[myStack->TOS];
    }
}

// Pop
int pop(St *myStack)
{
    if (isEmpty(myStack))
    {
        std::cout << "The Stack is Empty!" << std::endl;
        return -1; // Error value
    }
    else
    {
        int element = myStack->DATA[myStack->TOS];
        myStack->TOS--; // Move TOS down
        std::cout << element << " popped from the stack!" << std::endl;
        return element;
    }
}

int main()
{
    // Initializing a stack
    St myStack;
    myStack.TOS = -1; // Initialize TOS

    push(&myStack, 4);
    push(&myStack, 3);
    push(&myStack, 2);

    std::cout << "Top Element: " << peek(&myStack) << std::endl;

    pop(&myStack);
    std::cout << "Top Element: " << peek(&myStack) << std::endl;

    pop(&myStack);
    std::cout << "Top Element: " << peek(&myStack) << std::endl;

    return 0;
}
