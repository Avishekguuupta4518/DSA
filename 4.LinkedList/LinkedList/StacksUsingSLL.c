#include <stdio.h>
#include <stdlib.h>

struct DynamicStack
{
    int data;
    struct DynamicStack *next;
};
struct DynamicStack *top = NULL;

void initStack()
{
    top = NULL;
}

int isEmpty()
{
    return top == NULL;
}

void push(int value)
{
    struct DynamicStack *newNode = (struct DynamicStack *)malloc(sizeof(struct DynamicStack));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    else
    {
        newNode->data = value;
        newNode->next = NULL;
        if (top == NULL)
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
        printf("%d pushed onto stack\n", value);
    }
}

void pop()
{
    struct DynamicStack *temp = NULL;

    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    else
    {
        if (top->next == NULL)
        {
            temp = top;
            top = NULL;
            printf("%d is Popped from stack\n", temp->data);
            free(temp);
        }
        else
        {
            temp = top;
            top = top->next;
            printf("%d is Popped from stack\n", temp->data);
            free(temp);
        }
        
    }
}

void Display()
{
    struct DynamicStack *current = top;
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("1. Initialize Stack\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Display\n");
        printf("5. Check if Stack is Empty\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            initStack();
            printf("Stack initialized\n");
            break;
        case 2:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 3:
            pop();
            break;
        case 4:
            Display();
            break;
        case 5:
            if (isEmpty())
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}
