# Node class to represent each element in the stack
class Node:
    def __init__(self, value):
        self.value = value  # The value of the node
        self.next = None    # Pointer to the next node in the stack

# Stack class implementing a stack using a linked list
class Stack:
    def __init__(self):
        self.top = None   # Reference to the top of the stack
        self.size = 0     # Number of elements in the stack

    # Method to add an element to the stack
    def push(self, value):
        node = Node(value)  # Create a new node with the given value
        node.next = self.top  # Link the new node to the current top
        self.top = node  # Update the top to the new node
        self.size += 1   # Increment the size of the stack

    # Method to remove and return the top element of the stack
    def pop(self):
        if self.top is None:  # Check if the stack is empty
            raise IndexError("Pop from empty stack")  # Raise an error if the stack is empty
        value = self.top.value  # Retrieve the value of the top node
        self.top = self.top.next  # Update the top to the next node
        self.size -= 1  # Decrement the size of the stack
        return value  # Return the popped value

    # Method to view the top element without removing it
    def peek(self):
        if self.top is None:  # Check if the stack is empty
            raise IndexError("Peek from empty stack")  # Raise an error if the stack is empty
        return self.top.value  # Return the value of the top element

    # Method to check if the stack is empty
    def is_empty(self):
        return self.top is None  # Return True if the stack is empty, False otherwise

    # Method to get the size of the stack
    def get_size(self):
        return self.size  # Return the current size of the stack

# Example Usage
stack = Stack()
stack.push(10)  # Push 10 onto the stack
stack.push(20)  # Push 20 onto the stack
print(stack.peek())  # Output: 20 (Top element of the stack)
print(stack.pop())   # Output: 20 (Remove and return the top element)
print(stack.get_size())  # Output: 1 (Size of the stack after pop)
print(stack.is_empty())  # Output: False (The stack still has elements)

