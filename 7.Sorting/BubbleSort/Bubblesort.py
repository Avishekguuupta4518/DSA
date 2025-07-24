import time

def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr
arr = [64, 34, 25, 12, 22, 11, 90]
print("Original array:", arr)
start_time = time.time()
sorted_arr = bubbleSort(arr)
end_time = time.time()
print("Sorted array:", sorted_arr)
print(f"Time taken to execute: {end_time - start_time:.6f} seconds")
