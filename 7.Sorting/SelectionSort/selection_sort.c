#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int n)
{
    int i, j, pos, least;
    for (i = 0; i < n; i++)
    {
        least = arr[i];
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < least)
            {
                least = arr[j];
                pos = j;
            }
        }
        if (i != pos)
        {
            swap(&arr[i], &arr[pos]);
        }
    }
}

void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
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
    display(A, n);
    start = clock();
    SelectionSort(A, n);
    end = clock();
    display(A, n);
    diff = end - start;
    printf("The time taken is %f Seconds\n", (double)diff / CLOCKS_PER_SEC);
    return 0;
}