#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100 // Increased stack size for larger expressions

// Creating Stack
struct Stack
{
    int tos;
    char data[MAX];
};
typedef struct Stack stack;

// Function to check if the stack is full
int isFull(stack *s)
{
    return s->tos == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(stack *s)
{
    return s->tos == -1;
}

// Function to push an element into the stack
void push(stack *s, char ele)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->tos] = ele;
}

// Function to pop an element from the stack
char pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->tos--];
}

// Function to get the precedence of the operator
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}

// Function to convert infix expression to postfix expression
void infix_to_postfix(char *infix, char *postfix)
{
    stack s;
    s.tos = -1;
    char ch;
    int i = 0, j = 0;
    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
        {
            push(&s, ch);
        }
        else if (ch == ')')
        {
            while (s.data[s.tos] != '(')
                postfix[j++] = pop(&s);
            pop(&s); // Pop '(' without using s.tos-- directly
        }
        else if (isalnum(ch))
        { // Handle both letters and digits as operands
            postfix[j++] = ch;
        }
        else
        { // Operator
            while (!isEmpty(&s) && precedence(s.data[s.tos]) >= precedence(ch))
                postfix[j++] = pop(&s);
            push(&s, ch);
        }
    }
    while (!isEmpty(&s))
        postfix[j++] = pop(&s);
    postfix[j] = '\0';
}

// Function to evaluate the postfix expression
int evaluate_postfix(char *postfix)
{
    stack s;
    s.tos = -1;
    char ch;
    int i = 0, op1, op2;
    while ((ch = postfix[i++]) != '\0')
    {
        if (isdigit(ch))
        {
            push(&s, ch - '0'); // Convert char digit to int
        }
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch)
            {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            case '/':
                if (op2 == 0)
                {
                    printf("Division by zero error\n");
                    return -1;
                }
                push(&s, op1 / op2);
                break;
            default:
                printf("Invalid operator: %c\n", ch);
                return -1;
            }
        }
    }
    return pop(&s);
}

// Function to display the postfix expression
void display(char *postfix)
{
    printf("%s\n", postfix);
}

// Main Function
int main()
{
    char infix[100], postfix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: ");
    display(postfix);
    int result = evaluate_postfix(postfix);
    if (result != -1) // Ensure no error occurred during evaluation
        printf("Result: %d\n", result);
    return 0;
}
