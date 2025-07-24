#include <stdio.h>
#define MAX 5
#define True 1
#define False 0

struct stack {
    int tos;
    int item[MAX];
};

int isFull(struct stack *s) {
    if (s->tos == MAX - 1)
        return True;
    else
        return False;
}

int isEmpty(struct stack *s) {
    if (s->tos == -1)
        return True;
    else
        return False;
}

void push(struct stack *s, int element) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->tos++;
        s->item[s->tos] = element;
        printf("Pushed %d onto the stack.\n", element);
    }
}

int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int element = s->item[s->tos];
        s->tos--;
        printf("Popped %d from the stack.\n", element);
        return element;
    }
}

void display(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        for (int i = s->tos; i >= 0; i--) {
            printf("%d\n", s->item[i]);
        }
    }
}

int main() {
    int choice, element;
    struct stack s;
    s.tos = -1;

    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(&s, element);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            display(&s);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
