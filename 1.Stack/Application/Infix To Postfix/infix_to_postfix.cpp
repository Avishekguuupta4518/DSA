#include <iostream>
#include <stack>
#include <cctype> // For isdigit function

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
void infix_to_postfix(const std::string &infix, std::string &postfix)
{
    std::stack<char> s;
    for (char ch : infix)
    {
        if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) // Pop the '('
                s.pop();
        }
        else if (isalnum(ch))
        {
            postfix += ch; // Append operand directly
        }
        else
        { // Operator
            while (!s.empty() && precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
}

// Function to evaluate the postfix expression
int evaluate_postfix(const std::string &postfix)
{
    std::stack<int> s;
    for (char ch : postfix)
    {
        if (isdigit(ch))
        {                     // Operand
            s.push(ch - '0'); // Convert char digit to integer
        }
        else
        { // Operator
            if (s.size() < 2)
            {
                std::cerr << "Error: Invalid postfix expression" << std::endl;
                return -1;
            }
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            switch (ch)
            {
            case '+':
                s.push(op1 + op2);
                break;
            case '-':
                s.push(op1 - op2);
                break;
            case '*':
                s.push(op1 * op2);
                break;
            case '/':
                if (op2 == 0)
                {
                    std::cerr << "Error: Division by zero" << std::endl;
                    return -1;
                }
                s.push(op1 / op2);
                break;
            default:
                std::cerr << "Error: Unsupported operator " << ch << std::endl;
                return -1;
            }
        }
    }
    if (s.size() != 1)
    {
        std::cerr << "Error: Invalid postfix expression" << std::endl;
        return -1;
    }
    return s.top();
}

int main()
{
    // Get the string from the user
    std::string infix;
    std::cout << "Enter the infix expression (use single-digit operands): ";
    std::cin >> infix;

    // Convert infix to postfix
    std::string postfix;
    infix_to_postfix(infix, postfix);

    std::cout << "Postfix expression: " << postfix << std::endl;

    // Evaluate the postfix expression
    int result = evaluate_postfix(postfix);
    if (result != -1)
    {
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}
