#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    char data[MAX];
} Stack;

void push(Stack *s, char ch) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = ch;
}

char pop(Stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->data[s->top--];
}

char peek(Stack *s) {
    if (s->top == -1) return '\0';
    return s->data[s->top];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char *expr) {
    Stack s;
    s.top = -1;
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.top == -1 || !isMatchingPair(pop(&s), ch)) {
                return 0;
            }
        }
    }
    return s.top == -1;
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    scanf("%s", expr);

    if (isBalanced(expr)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are NOT balanced.\n");
    }

    return 0;
}
