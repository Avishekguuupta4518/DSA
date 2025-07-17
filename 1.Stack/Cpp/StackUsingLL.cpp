// CPP Implementation of Stack using Linked List
#include <iostream>

// Creating Node
struct Node
{
    int data;
    Node *next;
};

// Creating Stack
struct Stack
{
    Node *top;
};
typedef struct Stack ST;

// Is Empty
int isEmpty(Stack *myStack)
{
    if (myStack->top == NULL)
        return 1;
    return 0;
}

// Pop
int pop(Stack *myStack)
{
    if (isEmpty(myStack))
    {
        std::cout << "The Stack is Empty!" << std::endl;
        return -1; // Error value
    }
    Node *temp = myStack->top;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    int popped = temp->next->data;
    temp->next = NULL;
    return popped;
}

// Push
void push(Stack *myStack, int element)
{
    Node *newNode = new Node();
    newNode->data = element;
    newNode->next = myStack->top;
    myStack->top = newNode;
    std::cout << element << " pushed to the stack!" << std::endl;
}

// Peek
int peek(Stack *myStack)
{
    if (isEmpty(myStack))
    {
        std::cout << "The Stack is Empty!" << std::endl;
        return -1; // Error value
    }
    Node *temp = myStack->top;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->data;
}

// Traverse the stack
void traverse(Stack *myStack)
{
    if (isEmpty(myStack))
    {
        std::cout << "The Stack is Empty!" << std::endl;
    }
    else
    {
        Node *temp = myStack->top;
        while (temp != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

int main()
{
    // Initializing the stack
    ST *myStack = new ST();
    myStack->top = NULL;

    // Pushing elements to the stack
    push(myStack, 1);
    push(myStack, 2);
    push(myStack, 3);

    // Traversing the stack
    traverse(myStack);

    // Popping elements from the stack
    std::cout << pop(myStack) << " popped from the stack!" << std::endl;
    std::cout << pop(myStack) << " popped from the stack!" << std::endl;

    // Traversing the stack
    traverse(myStack);

    // Peeking the top element
    std::cout << "Top Element: " << peek(myStack) << std::endl;

    return 0;
}