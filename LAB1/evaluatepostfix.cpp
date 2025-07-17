#include <iostream>
#include <cctype>
#include <cstring>
#define SIZE 100
using namespace std;

class Stack
{
    int items[SIZE];
    int tos;

public:
    Stack()
    {
        tos = -1;
    }
    int isFull()
    {
        return tos == SIZE - 1;
    }
    int isEmpty()
    {
        return tos == -1;
    }
    void push(int value)
    {
        if (isFull())
            cout << "Stack overflow! Cannot push " << value << endl;
        else
            items[++tos] = value;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        else
        {
            return items[tos--];
        }
    }
};

int evaluatePostfix(const char *expr)
{
    Stack s;
    int g = 0;
    bool buildingNumber = false;
    int len = strlen(expr);
    for (int i = 0; i <= len; i++)
    {
        if (isdigit(expr[i]))
        {
            g = g * 10 + (expr[i] - '0');
            buildingNumber = true;
        }
        else
        {
            if (buildingNumber)
            {
                s.push(g);
                g = 0;
                buildingNumber = false;
            }
            char ch = expr[i];
            if (ch == ' ' || ch == '\0')
                continue;
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                int op2 = s.pop();
                int op1 = s.pop();
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
                s.push(result);
            }
        }
    }
    return s.pop();
}

int main()
{
    char expr[SIZE];
    cout << "Enter a postfix expression: ";
    cin.getline(expr, SIZE);
    int result = evaluatePostfix(expr);
    cout << "Result of the postfix expression: " << result << endl;
    return 0;
}