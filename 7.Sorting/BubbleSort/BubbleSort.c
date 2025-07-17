// Bubble Sort in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int A[100000], n;
    clock_t start, end;

    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 10000; 
    }
    printf("Original array:\n");
    display(A, n);

    start = clock();
    BubbleSort(A, n);
    end = clock();

    printf("Sorted array:\n");
    display(A, n);

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort: %lf seconds\n", time_taken);

    return 0;
}
