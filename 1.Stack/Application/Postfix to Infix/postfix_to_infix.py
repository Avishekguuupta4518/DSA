# Postfix to Infix Conversion

# Create a stack class
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
    
    def is_empty(self):
        return len(self.stack) == 0

# Function to convert postfix to infix
def postfix_to_infix(postfix):
    stack = Stack()
    
    for ch in postfix:
        if ch.isalnum():  # Check if the character is an operand
            stack.push(ch)
        else:  # If the character is an operator
            op2 = stack.pop()
            op1 = stack.pop()
            if op1 is None or op2 is None:
                raise ValueError("Invalid postfix expression")
            # Form a string "(op1 operator op2)" and push back to the stack
            expression = f"({op1}{ch}{op2})"
            stack.push(expression)
    
    # The final element in the stack is the infix expression
    if stack.is_empty() or len(stack.stack) != 1:
        raise ValueError("Invalid postfix expression")
    return stack.pop()

# Main Function
if __name__ == "__main__":
    postfix = input("Enter the postfix expression: ")
    try:
        infix = postfix_to_infix(postfix)
        print("Infix expression:", infix)
    except ValueError as e:
        print("Error:", e)
