# MergeSort implementation

import time 
 
def mergeSort(array):
    if len(array) > 1:
        r = len(array) // 2
        L = array[:r]
        M = array[r:]

        mergeSort(L)
        mergeSort(M)

        merge(array, L, M)

def merge(array, L, M):
    i = j = k = 0

    # Until we reach the end of either L or M, pick the smaller element
    # and place it in the correct position in the main array
    while i < len(L) and j < len(M):
        if L[i] < M[j]:
            array[k] = L[i]
            i += 1
        else:
            array[k] = M[j]
            j += 1
        k += 1

    # Copy the remaining elements from L, if any
    while i < len(L):
        array[k] = L[i]
        i += 1
        k += 1

    # Copy the remaining elements from M, if any
    while j < len(M):
        array[k] = M[j]
        j += 1
        k += 1

def display(array):
    for i in range(len(array)):
        print(array[i], end=" ")
    print()

if __name__ == '__main__':
    array = [6, 5, 12, 10, 9, 1]

    print("Original array:")
    display(array)

    mergeSort(array)

    print("Sorted array is:")
    display(array)
