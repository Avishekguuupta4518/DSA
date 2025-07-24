import time
import random

def max_heapify(arr, n, i):
    largest = i
    left = 2 * i   
    right = 2 * i + 1

    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        max_heapify(arr, n, largest)

def build_heap(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        max_heapify(arr, n, i)

def heap_sort(arr):
    n = len(arr)
    build_heap(arr)
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        max_heapify(arr, i, 0)

def display(arr):
    print(" ".join(map(str, arr)))

n = int(input("Enter n: "))
arr = [random.randint(1, 10000) for _ in range(n)]

print("Original array:")
display(arr)

start = time.time()
heap_sort(arr)
end = time.time()

print("Sorted array:")
display(arr)

print(f"Time taken to sort: {end - start:.6f} seconds")
