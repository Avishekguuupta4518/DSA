#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};
struct SLL *first = NULL, *last = NULL;

// Insert at beginning
void InsertionAtBeginning(int element)
{
    struct SLL *newNode = (struct SLL *)malloc(sizeof(struct SLL));
    newNode->data = element;
    newNode->next = NULL;
    if (first == NULL)
    {
        first = last = newNode;
    }
    else
    {
        newNode->next = first;
        first = newNode;
    }
    printf("%d is inserted at the beginning.\n", element);
}

// Insert at end
void InsertionAtEnd(int element)
{
    struct SLL *newNode = (struct SLL *)malloc(sizeof(struct SLL));
    newNode->data = element;
    newNode->next = NULL;
    if (first == NULL)
    {
        first = last = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
    printf("%d is inserted at the end.\n", element);
}

// Insert at specific position
void InsertionAtSpecificPosition(int element, int position)
{
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1)
    {
        InsertionAtBeginning(element);
        return;
    }
    struct SLL *newNode = (struct SLL *)malloc(sizeof(struct SLL));
    newNode->data = element;
    newNode->next = NULL;

    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        struct SLL *temp = first;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Position out of bounds\n");
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL)
        {
            last = newNode;
        }
        printf("%d is inserted at position %d.\n", element, position);
    }
}

// Delete from beginning
void DeletionFromBeginning()
{
    struct SLL *temp;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        free(temp);
    }
}

// Delete from end
void DeletionFromEnd()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct SLL *temp = first;
    int deletedValue;
    if (first->next == NULL)
    {
        deletedValue = first->data;
        first = last = NULL;
        free(temp);
        printf("%d is deleted from the end.\n", deletedValue);
        return;
    }
    while (temp->next != last)
    {
        temp = temp->next;
    }
    deletedValue = last->data;
    free(last);
    last = temp;
    last->next = NULL;
    printf("%d is deleted from the end.\n", deletedValue);
}

// Delete from specific position
void DeletionFromSpecificPosition(int position)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (position == 1)
    {
        DeletionFromBeginning();
        return;
    }
    struct SLL *temp = first;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    struct SLL *tempp = temp->next;
    int deletedValue = tempp->data;
    temp->next = tempp->next;
    if (tempp == last)
    {
        last = temp;
    }
    free(tempp);
    printf("%d is deleted from position %d.\n", deletedValue, position);
}

// Search for an element
void Searching(int element)
{
    struct SLL *temp = first;
    int pos = 1, found = 0;
    while (temp != NULL)
    {
        if (temp->data == element)
        {
            printf("Element %d found at position %d.\n", element, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (!found)
    {
        printf("Element %d not found.\n", element);
    }
}

// Display the list
void Display()
{
    struct SLL *temp = first;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Elements in the list: ");
        while (temp != NULL)
        {
            printf("[%d]", temp->data);
            if (temp->next != NULL)
                printf(" -> ");
            temp = temp->next;
        }
        printf(" -> NULL\n");
    }
}

int main()
{
    int choice, value, position;
    while (1)
    {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from specific position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            InsertionAtBeginning(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            InsertionAtEnd(value);
            break;
        case 3:
            printf("Enter value and position: ");
            scanf("%d %d", &value, &position);
            InsertionAtSpecificPosition(value, position);
            break;
        case 4:
            DeletionFromBeginning();
            break;
        case 5:
            DeletionFromEnd();
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            DeletionFromSpecificPosition(position);
            break;
        case 7:
            printf("Enter value to search: ");
            scanf("%d", &value);
            Searching(value);
            break;
        case 8:
            Display();
            break;
        case 9:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}