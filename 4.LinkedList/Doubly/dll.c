#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head, *last = NULL;

// Create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at front
void insertFront(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = last = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at front\n", data);
}

// Insert at end
void insertEnd(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = last = newNode;
    }
    else
    {
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
    printf("Inserted %d at end\n", data);
}

// Insert at a position
void insertAt(int data, int position)
{
    if (position <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        if (position == 1)
        {
            head = last = newNode;
            printf("Inserted %d at position %d\n", data, position);
        }
        else
        {
            printf("Position out of bounds\n");
            free(newNode);
        }
        return;
    }

    if (position == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
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

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    if (newNode->next == NULL)
        last = newNode;

    printf("Inserted %d at position %d\n", data, position);
}

// Delete from front
void deleteFront()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    printf("Deleted from front\n");
}

// Delete from end
void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = last = NULL;
        printf("Deleted from end\n");
        return;
    }

    struct Node *temp = last;
    last = last->prev;
    last->next = NULL;
    free(temp);
    printf("Deleted from end\n");
}

// Delete from a position
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

    if (position == 1)
    {
        struct Node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        printf("Deleted from position %d\n", position);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position; i++)
    {
        if (temp == NULL)
        {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    if (temp->next == NULL)
    {
        temp->prev->next = NULL;
        last = temp->prev;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted from position %d\n", position);
}

// Display the list
void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insertFront(10);
    insertFront(20);
    insertEnd(30);
    insertEnd(40);
    insertAt(50, 1);
    insertAt(60, 3);
    display();

    deleteFront();
    deleteEnd();
    deleteAt(2);
    display();

    return 0;
}