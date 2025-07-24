#include <stdio.h>
#include <time.h>

#define MAX 1000
#define EXP 10

void RadixSort(int arr[], int n) {
    int output[MAX]; // output array
    int count[EXP];  // count array

    // Find the maximum number to know number of digits
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        // Initialize count array
        for (int i = 0; i < EXP; i++) {
            count[i] = 0;
        }

        // Store count of occurrences in count[]
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % EXP]++;
        }

        // Change count[i] so that it contains actual position of this digit in output[]
        for (int i = 1; i < EXP; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % EXP] - 1] = arr[i];
            count[(arr[i] / exp) % EXP]--;
        }

        // Copy the output array to arr[]
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    clock_t start = clock();
    RadixSort(arr, n);
    clock_t end = clock();

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort: %lf seconds\n", time_taken);

    return 0;
}