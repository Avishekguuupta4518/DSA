# Changing the infix expression to postfix using stack

# Creating a stack class
class Stack:
    def __init__(self):
        self.stack = []
    
    def push(self, data):
        self.stack.append(data)
    
    def pop(self):
        if len(self.stack) > 0:
            return self.stack.pop()
        else:
            return None
    
    def top(self):
        if len(self.stack) > 0:
            return self.stack[-1]
        else:
            return None
    
    def is_empty(self):
        return len(self.stack) == 0
    

# Function to check the precedence of the operator
def precedence(op):
    if op == '+' or op == '-':
        return 1
    elif op == '*' or op == '/':
        return 2
    elif op == '^':
        return 3
    else:
        return 0
    

# Function to convert infix to postfix
def infix_to_postfix(exp):
    stack = Stack()
    postfix = ""
    for i in exp:
        if i.isalnum():
            postfix += i
        elif i == '(':
            stack.push(i)
        elif i == ')':
            while stack.top() != '(':
                postfix += stack.pop()
            stack.pop()
        else:
            while not stack.is_empty() and precedence(i) <= precedence(stack.top()):
                postfix += stack.pop()
            stack.push(i)
    while not stack.is_empty():
        postfix += stack.pop()
    return postfix


# Testing the function
exp = "a+b*(c^d-e)^(f+g*h)-i"
print(infix_to_postfix(exp))