#include <stdio.h>
#include <stdlib.h>

struct dll
{
    int data;
    struct dll *prev;
    struct dll *next;
};
struct dll *head, *tail = NULL;

// INSERTION
// At Front ::

void insertAtFront(int element)
{
    struct dll *newNode;
    newNode = (struct dll *)malloc(sizeof(struct dll));
    if (!newNode)
    {
        printf("memory not allocated.\n");
        return;
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = element;
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}
// At End ::

void insertAtEnd(int element)
{
    struct dll *newNode;
    newNode = (struct dll *)malloc(sizeof(struct dll));
    if (!newNode)
    {
        printf("memory not allocated.\n");
        return;
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = element;
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// At Position ::

void insertAtPosition(int element, int pos)
{
    if (pos == 1)
    {
        insertAtFront(element);
        return;
    }
    if (head == NULL)
    {
        printf("%d not inserted.out of range\n", element);
        return;
    }
    int i = 1;
    struct dll *temp;
    temp = head;
    while (1)
    {
        i++;
        temp = temp->next;
        if (temp == NULL && i < pos)
        {
            printf("%d not inserted.out of range\n", element);
            return;
        }
        else if (temp != NULL && i == pos)
        {
            struct dll *newNode;
            newNode = (struct dll *)malloc(sizeof(struct dll));
            if (!newNode)
            {
                printf("memory not allocated.\n");
                return;
            }
            newNode->data = element;
            newNode->next = temp;
            newNode->prev = temp->prev;
            (temp->prev)->next = newNode;
            temp->prev = newNode;
            return;
        }
        else if (temp == NULL && pos == i)
        {
            insertAtEnd(element);
            return;
        }
    }
}

// Display

void display()
{
    struct dll *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// DELETION
// From Begining ::

void deleteFromBeg()
{
    struct dll *temp;
    if (head == NULL)
    {
        printf("Already Empty.\n");
    }
    else if (head->next == NULL)
    {
        temp = head;
        head = tail = NULL;
        free(temp);
        temp = NULL;
    }
    else
    {
        temp = head;
        head = temp->next;
        head->prev = NULL;
        free(temp);
        temp = NULL;
    }
}
void deleteFromEnd()
{
    struct dll *temp;
    if (head == NULL)
    {
        printf("Nothing to delete.\n");
        return;
    }
    else if (head->next == NULL)
    {
        temp = head;
        head = tail = NULL;
        free(temp);
        temp = NULL;
        return;
    }
    temp = tail;
    tail = temp->prev;
    tail->next = NULL;
    free(temp);
    temp = NULL;
}
void deleteFromPosition(int pos)
{
    struct dll *temp;
    if (pos == 1)
    {
        deleteFromBeg();
        return;
    }
    int i = 1;
    temp = head;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
        if (i == pos && temp->next != NULL)
        {
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            free(temp);
            temp = NULL;
            return;
        }
        else if (i == pos && temp->next == NULL)
        {
            tail = temp->prev;
            tail->next = NULL;
            free(temp);
            temp = NULL;
            return;
        }
    }
    printf("Out of Range.\n");
}

// Reversing Doubly LINKED LIST

void swap(int *a1, int *a2)
{
    int temp;
    temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}
void reverseDll()
{
    struct dll *headTemp, *tailTemp;
    headTemp = head;
    tailTemp = tail;
    while ((tailTemp != headTemp) && (headTemp->prev != tailTemp))
    {
        swap(&(headTemp->data), &(tailTemp->data));
        tailTemp = tailTemp->prev;
        headTemp = headTemp->next;
    }
}

int main()
{
    insertAtFront(5);
    display();
    insertAtFront(15);
    display();
    insertAtEnd(6);
    display();
    insertAtEnd(16);
    display();
    insertAtPosition(10, 2);
    display();
    insertAtPosition(12, 5);
    display();
    insertAtPosition(0, 1);
    display();
    insertAtPosition(7, 2);
    display();
    reverseDll();
    display();
    return 0;
}