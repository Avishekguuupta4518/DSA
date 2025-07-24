# Sorting

## Definition

**Sorting** is the process of arranging elements in a particular order (typically ascending or descending). Sorting is fundamental in computer science for optimizing data searching, organizing information, and enabling efficient algorithms.

---

## Key Sorting Algorithms

1. **Bubble Sort**
   - Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

2. **Selection Sort**
   - Selects the smallest (or largest) element from the unsorted part and swaps it with the first unsorted element.

3. **Insertion Sort**
   - Builds the sorted array one item at a time by inserting each element into its correct position.

4. **Merge Sort**
   - Divides the array into halves, sorts each half, and merges them back together.

5. **Quick Sort**
   - Selects a 'pivot' element and partitions the array around the pivot, recursively sorting the partitions.

6. **Heap Sort**
   - Converts the array into a heap data structure and repeatedly extracts the maximum (or minimum) element.

---

## Applications

- **Searching**: Many search algorithms require sorted data.
- **Data Analysis**: Sorting is used in statistics, analytics, and reporting.
- **Deduplication**: Sorted data makes it easier to remove duplicates.
- **Algorithm Optimization**: Some algorithms (like binary search) require sorted input.

---

## Implementation Examples

### 1. Bubble Sort (Python)

```python
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

# Example usage
arr = [64, 34, 25, 12, 22, 11, 90]
print(bubble_sort(arr))  # Output: [11, 12, 22, 25, 34, 64, 90]
```

### 2. Merge Sort (Python)

```python
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]

        merge_sort(L)
        merge_sort(R)

        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
    return arr

# Example usage
arr = [12, 11, 13, 5, 6, 7]
print(merge_sort(arr))  # Output: [5, 6, 7, 11, 12, 13]
```

---

## Best Practices

1. **Choose the Right Algorithm**:
   - For small datasets, simple sorts like insertion or bubble sort may suffice.
   - For large datasets, use efficient algorithms like merge sort or quick sort.

2. **Consider Stability**:
   - Stable sorts maintain the relative order of equal elements (important for some applications).

3. **Test Edge Cases**:
   - Empty arrays, arrays with one element, already sorted arrays, and arrays with duplicate values.

---

## Additional Notes

- Sorting is a building block for many advanced algorithms.
- Most programming languages provide built-in sorting functions optimized for performance.

---

### Resources

- [GeeksforGeeks on Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)
-