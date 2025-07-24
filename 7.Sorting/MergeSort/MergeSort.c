#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
    int b[100];
    int i = l;
    int j = m+1;
    int k = l;
    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }
    for (; i <= m; i++, k++)
        b[k] = arr[i];
    for (; j <= r; j++, k++)
        b[k] = arr[j];
    for (i = l; i <= r; i++)
        arr[i] = b[i];
}

void MergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[100000], n, i;
    srand(time(NULL));
    clock_t start, end, diff;
    printf("Enter n:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        A[i] = rand();
    }
    printf("Original array:\n");
    display(A, n);
    start = clock();
    MergeSort(A, 0, n - 1);
    end = clock();
    printf("Sorted array:\n");
    display(A, n);
    diff = end - start;
    printf("The time taken is %f Seconds\n", (double)diff / CLOCKS_PER_SEC);
    return 0;
}