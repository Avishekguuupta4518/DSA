#include <iostream>
#include <stack>
#include <string>
#include <cctype>  // For isdigit function
#include <cstdlib> // For atoi function

// Function to create a new infix string
std::string createInfixString(const std::string &op1, const std::string &op2, char oper)
{
    return "(" + op1 + oper + op2 + ")";
}

// Function to convert postfix to infix and evaluate
int postfixToInfixAndEvaluate(const std::string &postfix, std::string &infix)
{
    std::stack<std::string> infixStack; // Stack for infix expression
    std::stack<int> evalStack;          // Stack for evaluation

    for (char ch : postfix)
    {
        if (isdigit(ch))
        {
            // Push operand onto both stacks
            std::string operand(1, ch); // Convert char to string
            infixStack.push(operand);
            evalStack.push(ch - '0'); // Convert char digit to integer
        }
        else
        {
            if (infixStack.size() < 2 || evalStack.size() < 2)
            {
                std::cerr << "Error: Invalid postfix expression" << std::endl;
                return 0;
            }

            // Pop two operands from the infix stack
            std::string op2 = infixStack.top();
            infixStack.pop();
            std::string op1 = infixStack.top();
            infixStack.pop();

            // Create infix string and push back to the stack
            infixStack.push(createInfixString(op1, op2, ch));

            // Pop two operands from the evaluation stack
            int val2 = evalStack.top();
            evalStack.pop();
            int val1 = evalStack.top();
            evalStack.pop();

            // Perform operation and push result back to the evaluation stack
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
                    std::cerr << "Error: Division by zero" << std::endl;
                    return 0;
                }
                result = val1 / val2;
                break;
            default:
                std::cerr << "Error: Invalid operator '" << ch << "'" << std::endl;
                return 0;
            }
            evalStack.push(result);
        }
    }

    if (infixStack.size() != 1 || evalStack.size() != 1)
    {
        std::cerr << "Error: Invalid postfix expression" << std::endl;
        return 0;
    }

    infix = infixStack.top(); // Final infix expression
    return evalStack.top();   // Final evaluation result
}

int main()
{
    std::string postfix;
    std::string infix;

    std::cout << "Enter the postfix expression (use single-digit numbers): ";
    std::cin >> postfix;

    int result = postfixToInfixAndEvaluate(postfix, infix);

    if (!infix.empty())
    {
        std::cout << "Infix expression: " << infix << std::endl;
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}
