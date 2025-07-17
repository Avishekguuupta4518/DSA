// reverse a linked list using a stack

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to reverse a singly linked list using a stack
void reverseSll(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    int *stack = (int *)malloc(count * sizeof(int));
    int top = -1;
    temp = head;
    while (temp)
    {
        stack[++top] = temp->data;
        temp = temp->next;
    }

    temp = head;
    while (temp)
    {
        temp->data = stack[top--];
        temp = temp->next;
    }
    free(stack);
}


void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void append(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next)
        last = last->next;
    last->next = new_node;
}

int main()
{
    struct Node *head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Original list:\n");
    printList(head);

    reverseSll(head); 

    printf("Reversed list:\n");
    printList(head);

    return 0;
}