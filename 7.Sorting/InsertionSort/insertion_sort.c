#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
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
    int arr[100000], n;
    clock_t start, end;

    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }

    printf("Original array:\n");
    display(arr, n);

    start = clock();
    InsertionSort(arr, n);
    end = clock();

    printf("Sorted array:\n");
    display(arr, n);

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort: %lf seconds\n", time_taken);

    return 0;
}
