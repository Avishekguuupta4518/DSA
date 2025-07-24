#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    int top;
    char data[MAX];
} Stack;

void push(Stack *s, char ch) {
    s->data[++s->top] = ch;
}

char pop(Stack *s) {
    return s->data[s->top--];
}

int main() {
    char str[MAX];
    Stack s;
    s.top = -1;

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }

    printf("Reversed string: ");
    while (s.top != -1) {
        printf("%c", pop(&s));
    }

    printf("\n");
    return 0;
}
