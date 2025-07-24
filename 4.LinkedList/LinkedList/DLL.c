#include <stdio.h>
#include <stdlib.h>
struct DLL
{
    int data;
    struct DLL *next;
    struct DLL *prev;
};
struct DLL *first = NULL, *last = NULL;

void InsertionAtBeginning(int element)
{
    struct DLL *newNode = (struct DLL *)malloc(sizeof(struct DLL));
    newNode->data = element;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (first == NULL)
    {
        first = last = newNode;
    }
    else
    {
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    }
    printf("%d is inserted at the beginning.\n", element);
}

void InsertionAtEnd(int element)
{
    struct DLL *newNode = (struct DLL *)malloc(sizeof(struct DLL));
    newNode->data = element;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (first == NULL)
    {
        first = last = newNode;
    }
    else
    {
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
    printf("%d is inserted at the end.\n", element);
}

void InsertionAtSpecificPosition(int element, int position)
{
    struct DLL *newNode = (struct DLL *)malloc(sizeof(struct DLL));
    newNode->data = element;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (position == 1)
    {
        InsertionAtBeginning(element);
        return;
    }

    struct DLL *temp = first;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position is out of bounds. Inserting at the end instead.\n");
        InsertionAtEnd(element);
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;

        if (newNode->next == NULL)
            last = newNode;

        printf("%d is inserted at position %d.\n", element, position);
    }
}
void DeletionFromBeginning()
{
    struct DLL *temp;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        printf("%d is going to be deleted from the beginning.\n", temp->data);
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        first->prev = NULL;
        printf("%d is going to be deleted from the beginning.\n", temp->data);
        free(temp);
    }
}

void DeletionFromEnd()
{
    struct DLL *temp;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        printf("%d is going to be deleted from the end.\n", temp->data);
        free(temp);
    }
    else
    {
        temp = last;
        last = last->prev;
        last->next = NULL;
        printf("%d is going to be deleted from the end.\n", temp->data);
        free(temp);
    }
}

void DeletionFromSpecificPosition(int position)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct DLL *temp = first;

    if (position == 1)
    {
        DeletionFromBeginning();
        return;
    }

    for (int i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position is out of bounds.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp == last)
        last = temp->prev;

    printf("%d is going to be deleted from position %d.\n", temp->data, position);
    free(temp);
}

void Display()
{
    struct DLL *temp;
    temp = first;
    if (first == NULL)

        printf("List is empty\n");
    else
    {
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void Display_Reverse()
{
    struct DLL *temp;
    temp = last;
    if (last == NULL)

        printf("List is empty\n");
    else
    {
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->prev;
        }
        printf("NULL\n");
    }
}

void Search(int key)
{
    int flag = 0;
    struct DLL *temp;
    if (first == NULL)
        printf("list is empty");
    else
    {
        temp = first;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                printf("SEARCH SUCCESSFUL: %d found in the list\n", key);
                flag = 1;
                break;
            }
            temp = temp->next;
        }
    }
    if (flag == 0)
        printf("SEARCH UNSUCCESSFUL: %d not found in the list\n", key);
}


int main()
{
    int choice, element, position;
    while (1)
    {
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specific Position\n");
        printf("7. Display List\n");
        printf("8. Display List in Reverse\n");
        printf("9. Search Element\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element to insert at beginning: ");
                scanf("%d", &element);
                InsertionAtBeginning(element);
                break;
            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d", &element);
                InsertionAtEnd(element);
                break;
            case 3:
                printf("Enter element to insert and position: ");
                scanf("%d %d", &element, &position);
                InsertionAtSpecificPosition(element, position);
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
                Display();
                break;
            case 8:
                Display_Reverse();
                break;
            case 9:
                printf("Enter element to search: ");
                scanf("%d", &element);
                Search(element);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
