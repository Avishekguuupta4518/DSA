import time

def selectionSort(array):
    for i in range(len(array)):
        minIndex = i
        for j in range(i + 1, len(array)):
            if array[j] < array[minIndex]:
                minIndex = j
        array[i], array[minIndex] = array[minIndex], array[i]
    return array

time1 = time.time()
arr = [64, 34, 25, 12, 22, 11, 90]
print(selectionSort(arr))
time2 = time.time()
print(f"Time taken to execute : {time2 - time1}")