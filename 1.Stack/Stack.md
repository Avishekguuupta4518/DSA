# Stacks

## Definition

A **stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle. This means that the last element added to the stack is the first one to be removed.

---

## Key Operations

1. **Push**

   - Adds an element to the top of the stack.

2. **Pop**

   - Removes the top element from the stack.

3. **Peek (or Top)**

   - Retrieves the top element without removing it.

4. **isEmpty**

   - Checks if the stack is empty.

5. **Size**
   - Returns the number of elements in the stack.

---

## Applications

- **Expression Evaluation**: Used in parsing and evaluating expressions (e.g., converting infix to postfix notation).
- **Backtracking**: Helps in scenarios like solving mazes, navigating directories, or undo functionality in applications.
- **Function Call Management**: Used by programming languages to manage function calls and recursion.
- **Syntax Parsing**: Validating parentheses in expressions or checking XML/HTML tags.

---

## Implementation Examples

### 1. Using Arrays (or Lists in Python)

```python
class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        raise IndexError("Pop from empty stack")

    def peek(self):
        if not self.is_empty():
            return self.items[-1]
        raise IndexError("Peek from empty stack")

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)

# Example usage
stack = Stack()
stack.push(10)
stack.push(20)
print(stack.peek())  # Output: 20
print(stack.pop())   # Output: 20
print(stack.is_empty())  # Output: False
```

### 2. Using Linked List

```python
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class Stack:
    def __init__(self):
        self.top = None
        self._size = 0

    def push(self, value):
        new_node = Node(value)
        new_node.next = self.top
        self.top = new_node
        self._size += 1

    def pop(self):
        if self.top is None:
            raise IndexError("Pop from empty stack")
        value = self.top.value
        self.top = self.top.next
        self._size -= 1
        return value

    def peek(self):
        if self.top is None:
            raise IndexError("Peek from empty stack")
        return self.top.value

    def is_empty(self):
        return self.top is None

    def size(self):
        return self._size

# Example usage
stack = Stack()
stack.push(10)
stack.push(20)
print(stack.peek())  # Output: 20
print(stack.pop())   # Output: 20
print(stack.is_empty())  # Output: False
```

---

## Best Practices

1. **Error Handling**:

   - Always check for underflow when performing `pop` or `peek` operations.

2. **Optimize Memory Usage**:

   - Use linked lists for dynamic stacks when the size is unpredictable.

3. **Test Edge Cases**:
   - Empty stack operations.
   - Very large stack size.

---

## Additional Notes

- Stacks are a fundamental part of many algorithms and problem-solving approaches.
- They are widely supported by libraries in most programming languages.

---

### Resources

- [GeeksforGeeks on Stacks](https://www.geeksforgeeks.org/stack-data-structure/)
- [Python Documentation - Collections: deque](https://docs.python.org/3/library/collections.html#collections.deque)
