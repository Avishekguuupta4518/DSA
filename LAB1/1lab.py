def evaluate_postfix(expression):
    stack = []
    postfix_tokens = expression.split()

    for token in postfix_tokens:    #space separated
        if token.isdigit():
            stack.append(float(token))
        else:
            op2 = stack.pop()
            op1 = stack.pop()
            if token == '+':
                stack.append(op1 + op2)
            elif token == '-':
                stack.append(op1 - op2)
            elif token == '*':
                stack.append(op1 * op2)
            elif token == '/':
                stack.append(op1 / op2)
    return stack.pop()

postfix = input("Enter a postfix expression:")
result = evaluate_postfix(postfix)

print(f"Result of the postfix expression '{postfix}': {result}")