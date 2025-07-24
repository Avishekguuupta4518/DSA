#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isdigit function

// Define the maximum size of the stack
#define MAX 100

// Define a stack structure
struct Stack
{
    char *items[MAX];
    int top;
};

// Define a stack structure for integers (for evaluation)
struct IntStack
{
    int items[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack *s)
{
    s->top = -1;
}

void initIntStack(struct IntStack *s)
{
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

int isIntStackEmpty(struct IntStack *s)
{
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *s, char *item)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = item;
}

void pushInt(struct IntStack *s, int item)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = item;
}

// Function to pop an element from the stack
char *pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return NULL;
    }
    return s->items[s->top--];
}

int popInt(struct IntStack *s)
{
    if (isIntStackEmpty(s))
    {
        printf("Stack Underflow\n");
        return 0;
    }
    return s->items[s->top--];
}

// Function to create a new string dynamically
char *createString(const char *str1, const char *str2, char operator)
{
    char *result = (char *)malloc(strlen(str1) + strlen(str2) + 4); // 2 for parentheses, 1 for operator, and 1 for '\0'
    sprintf(result, "(%s%c%s)", str1, operator, str2);
    return result;
}

// Function to convert postfix to infix and evaluate
int postfix_to_infix_and_evaluate(const char *postfix, char *infix)
{
    struct Stack s;
    struct IntStack evalStack;
    initStack(&s);
    initIntStack(&evalStack);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        // If operand, push onto both stacks
        if (isdigit(ch))
        {
            char *operand = (char *)malloc(2); // Allocate memory for a single character and null terminator
            operand[0] = ch;
            operand[1] = '\0';
            push(&s, operand);
            pushInt(&evalStack, ch - '0'); // Convert char to int and push onto evaluation stack
        }
        else
        { // Operator
            if (s.top < 1 || evalStack.top < 1)
            {
                printf("Error: Invalid postfix expression\n");
                return 0;
            }
            // Pop operands for infix conversion
            char *op2 = pop(&s);
            char *op1 = pop(&s);
            char *expr = createString(op1, op2, ch);
            free(op1);
            free(op2);
            push(&s, expr);

            // Pop operands for evaluation
            int val2 = popInt(&evalStack);
            int val1 = popInt(&evalStack);
            int result = 0;

            switch (ch)
            {
            case '+':
                result = val1 + val2;
                break;
            case '-':
                result = val1 - val2;
                break;
            case '*':
                result = val1 * val2;
                break;
            case '/':
                if (val2 == 0)
                {
                    printf("Error: Division by zero\n");
                    return 0;
                }
                result = val1 / val2;
                break;
            default:
                printf("Error: Invalid operator '%c'\n", ch);
                return 0;
            }
            pushInt(&evalStack, result);
        }
    }

    if (s.top != 0 || evalStack.top != 0)
    {
        printf("Error: Invalid postfix expression\n");
        return 0;
    }

    strcpy(infix, pop(&s));    // Copy the final infix expression
    return popInt(&evalStack); // Return the final evaluation result
}

int main()
{
    char postfix[100];
    char infix[200]; // Assuming the infix expression won't exceed 200 characters

    printf("Enter the postfix expression (use single-digit numbers): ");
    scanf("%s", postfix);

    int result = postfix_to_infix_and_evaluate(postfix, infix);

    printf("Infix expression: %s\n", infix);
    printf("Result: %d\n", result);

    return 0;
}
