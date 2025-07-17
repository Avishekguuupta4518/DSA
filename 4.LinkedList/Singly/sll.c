#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head, *last = NULL;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) // Always check for memory allocation success.
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode; // Return the new node
}

void insertFront(int data)
{
    struct Node *newNode = createNode(data);
    // List is empty
    if (head == NULL)
    {
        head = last = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    printf("Inserted %d at front\n", data);
}

void insertEnd(int data)
{
    struct Node *newNode = createNode(data);
    // List is empty
    if (head == NULL)
    {
        head = last = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
    printf("Inserted %d at end\n", data);
}

void insertAt(int data, int position)
{
    if (position <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *newNode = createNode(data);

    if (position == 1) // Insert at the front
    {
        newNode->next = head;
        head = newNode;
        if (last == NULL) // If the list was empty, update last
            last = newNode;
        printf("Inserted %d at position %d\n", data, position);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (temp == NULL)
        {
            printf("Position out of bounds\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) // Position out of bounds
    {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    if (newNode->next == NULL) // Update last if inserted at the end
        last = newNode;

    printf("Inserted %d at position %d\n", data, position);
}

void deleteFront()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted from front\n");
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) // Only one node
    {
        free(head);
        head = last = NULL;
        printf("Deleted from end\n");
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    last = temp;
    printf("Deleted from end\n");
}

void deleteAt(int position)
{
    if (position <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (position == 1) // Delete from front
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        printf("Deleted from position %d\n", position);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (temp == NULL)
        {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) // Position out of bounds
    {
        printf("Position out of bounds\n");
        return;
    }

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
    if (temp->next == NULL) // Update last if deleted from end
        last = temp;

    printf("Deleted from position %d\n", position);
}

void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insertFront(1);
    insertEnd(3);
    insertAt(2, 2);
    insertAt(4, 4);
    insertEnd(5);
    display();

    deleteFront();
    deleteEnd();
    deleteAt(2);
    display();

    return 0;
}