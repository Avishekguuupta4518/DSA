# Stack Implementation in Python Using Lists
class Stack:
    def __init__(self):
        self.items = []  # Initialize an empty list to store stack elements
    
    # Method to add an element to the stack
    def push(self, item):
        self.items.append(item)  # Append the item to the end of the list
    
    # Method to remove and return the top element of the stack
    def pop(self):
        if not self.is_empty():  # Check if the stack is not empty
            return self.items.pop()  # Remove and return the last element
        raise IndexError("pop from empty stack")  # Raise an error if the stack is empty

    # Method to view the top element without removing it
    def peek(self):
        if not self.is_empty():  # Check if the stack is not empty
            return self.items[-1]  # Return the last element without removing it
        raise IndexError("peek from empty stack")  # Raise an error if the stack is empty

    # Method to check if the stack is empty
    def is_empty(self):
        return len(self.items) == 0  # Return True if the list is empty, False otherwise

    # Method to get the size of the stack
    def size(self):
        return len(self.items)  # Return the number of elements in the stack

# Example Usage
stack = Stack()  # Create an instance of the Stack class
stack.push(1)    # Push 1 onto the stack
stack.push(2)    # Push 2 onto the stack

print(stack.peek())  # Output: 2 (Top element of the stack)
print(stack.pop())   # Output: 2 (Remove and return the top element)
print(stack.is_empty())  # Output: False (The stack still has elements)
print(stack.size())  # Output: 1 (Size of the stack after popping one element)
