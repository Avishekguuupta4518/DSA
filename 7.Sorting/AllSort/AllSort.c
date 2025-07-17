#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// Utility swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 1. Bubble Sort
void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// 2. Selection Sort
void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

// 3. Insertion Sort
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// 4. Merge Sort
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
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// 5. Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high], i = (low - 1);
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

// 6. Heap Sort
void heap(int arr[], int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heap(arr, n, largest);
    }
}
void HeapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heap(arr, i, 0);
    }
}

// 7. Shell Sort
void ShellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// 8. Radix Sort (for non-negative integers)
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSortRadix(int arr[], int n, int exp)
{
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    free(output);
}
void RadixSort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortRadix(arr, n, exp);
}

// Print array
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int original[] = {13, 4, 12, 25, 7, 15, 4, 2};
    int n = sizeof(original) / sizeof(original[0]);
    int arr[n];
    int choice;

    printf("Welcome to the Sorting Algorithms Program!\n");
    while (1)
    {
        // Restore original array before each sort
        for (int i = 0; i < n; i++)
            arr[i] = original[i];

        printf("\nChoose sorting algorithm:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Heap Sort\n");
        printf("7. Counting Sort\n");
        printf("8. Radix Sort\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 9)
            break;

        clock_t start = clock();

        switch (choice)
        {
        case 1:
            BubbleSort(arr, n);
            break;
        case 2:
            SelectionSort(arr, n);
            break;
        case 3:
            InsertionSort(arr, n);
            break;
        case 4:
            MergeSort(arr, 0, n - 1);
            break;
        case 5:
            QuickSort(arr, 0, n - 1);
            break;
        case 6:
            HeapSort(arr, n);
            break;
        case 7:
            ShellSort(arr, n);
            break;
        case 8:
            RadixSort(arr, n);
            break;
        default:
            printf("Invalid choice!\n");
            continue;
        }

        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Sorted array:\n");
        display(arr, n);
        printf("Time taken: %lf seconds\n", time_taken);
    }

    printf("Thank you for using the program.\n");
    return 0;
}
