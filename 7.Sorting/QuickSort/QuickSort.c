#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int x = l;
    int y = r;

    while (x < y)
    {
        while (arr[x] <= pivot && x < r)
            x++;
        while (arr[y] > pivot)
            y--;
        if (x < y)
            swap(&arr[x], &arr[y]);
    }
    swap(&arr[l], &arr[y]);
    return y;
}

void QuickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        QuickSort(arr, l, p - 1);
        QuickSort(arr, p + 1, r);
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n, arr[100000];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }

    printf("Unsorted array:\n");
    display(arr, n);

    clock_t start = clock();
    QuickSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("Sorted array:\n");
    display(arr, n);

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %lf seconds\n", n, time_taken);
    return 0;
}
