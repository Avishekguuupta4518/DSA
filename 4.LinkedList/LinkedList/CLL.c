// Implementation of Circular Linked List

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
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFront(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = last = newNode;
        last->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        last->next = head;
    }
    printf("Inserted %d at front\n", data);
}

void insertEnd(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = last = newNode;
        last->next = head;
    }
    else
    {
        last->next = newNode;
        last = newNode;
        last->next = head;
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

    if (head == NULL)
    {
        if (position == 1)
        {
            head = last = newNode;
            last->next = head;
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
        head = newNode;
        last->next = head;
        printf("Inserted %d at position %d\n", data, position);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (temp == last)
        {
            printf("Position out of bounds\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    if (temp == last)
    {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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
    if (head == last)
    {
        head = last = NULL;
    }
    else
    {
        head = head->next;
        last->next = head;
    }
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

    if (head == last)
    {
        free(head);
        head = last = NULL;
        printf("Deleted from end\n");
        return;
    }

    struct Node *temp = head;
    while (temp->next != last)
        temp = temp->next;

    temp->next = head;
    free(last);
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

    if (position == 1)
    {
        struct Node *temp = head;
        if (head == last)
        {
            head = last = NULL;
        }
        else
        {
            head = head->next;
            last->next = head;
        }
        free(temp);
        printf("Deleted from position %d\n", position);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (temp == last)
        {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == last)
    {
        printf("Position out of bounds\n");
        return;
    }

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
    if (temp->next == head)
        last = temp;

    printf("Deleted from position %d\n", position);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
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
    insertAt(70, 6);
    display();

    deleteFront();
    deleteEnd();
    deleteAt(2);
    deleteAt(3);
    deleteAt(4);
    deleteAt(1);
    display();

    return 0;
}