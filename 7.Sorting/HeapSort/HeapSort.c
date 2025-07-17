#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

void MAX_HEAP(int arr[], int i, int n) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l <= n && arr[l] > arr[largest])
        largest = l;
    if (r <= n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        MAX_HEAP(arr, largest, n);
    }
}

void BuildHeap(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--)
        MAX_HEAP(arr, i, n);
}

void HeapSort(int arr[], int n) {
    BuildHeap(arr, n);
    for (int i = n; i >= 2; i--) {
        swap(&arr[1], &arr[i]);
        MAX_HEAP(arr, 1, i - 1);
    }
}

void display(int arr[], int size) {
    for (int i = 1; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int A[100001], n;
    clock_t start, end;

    printf("Enter n (up to 100000): ");
    scanf("%d", &n);

    // Fill array from index 1 for 1-based indexing
    for (int i = 1; i <= n; i++) {
        A[i] = rand() % 10000;
    }

    printf("Original array:\n");
    display(A, n);

    start = clock();
    HeapSort(A, n);
    end = clock();

    printf("Sorted array:\n");
    display(A, n);

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort: %lf seconds\n", time_taken);

    return 0;
}
