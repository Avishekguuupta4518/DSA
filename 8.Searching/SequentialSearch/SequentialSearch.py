def sequential_search(arr, target):
    for index, element in enumerate(arr):
        if element == target:
            return index
    return -1

if __name__ == "__main__":
    arr = [1, 3, 5, 7, 9]
    target = 9
    result = sequential_search(arr, target)
    if result != -1:
        print(f"Element found at index {result}")
    else:
        print("Element not found")