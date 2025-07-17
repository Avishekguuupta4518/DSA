def sequential_search(arr, target):
    """
    Perform a sequential search for the target in the given array.

    Parameters:
    arr (list): The list to search through.
    target: The element to search for.

    Returns:
    int: The index of the target if found, otherwise -1.
    """
    for index, element in enumerate(arr):
        if element == target:
            return index
    return -1

# Example usage:
if __name__ == "__main__":
    arr = [1, 3, 5, 7, 9]
    target = 5
    result = sequential_search(arr, target)
    if result != -1:
        print(f"Element found at index {result}")
    else:
        print("Element not found")