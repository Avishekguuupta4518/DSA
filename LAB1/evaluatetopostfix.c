#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

#define True 1
#define False 0

struct Stack
{
    int items[SIZE];
    int tos;
};

int isFull(struct Stack *s)
{
    if (s->tos == SIZE - 1)
        return True;
    else
        return False;
}

int isEmpty(struct Stack *s)
{
    if (s->tos == -1)
        return True;
    else
        return False;
}

void push(struct Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack overflow! Cannot push %d\n", value);
    }
    else
    {
        s->items[++(s->tos)] = value;
    }
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!\n");
        return -1;
    }
    else
    {
        return s->items[(s->tos)--];
    }
}

int evaluatePostfix(char *expr)
{
    struct Stack s;
    s.tos = -1;
    int g = 0;
    int len = strlen(expr) - 1;
    for (int i = 0; i < len; i++) 
    {
        if (isdigit(expr[i]))
        {
            g = g * 10 + (expr[i] - '0');
            continue;
        }
        if (g > 0)
        {
            push(&s, g);
            g = 0;
        }
        char ch = expr[i];

        if (ch == ' ')
            continue;

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int op2 = pop(&s);
            int op1 = pop(&s);
            int result;
            switch (ch)
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}

int main()
{
    char expr[SIZE];
    struct Stack s;
    s.tos = -1;

    printf("Enter a postfix expression : ");
    fgets(expr, sizeof(expr), stdin);
    printf("Your expression is: %s\n", expr);

    int result = evaluatePostfix(expr);
    printf("Result of the postfix expression: %d\n", result);

    return 0;
}
