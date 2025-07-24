// binary_search_random.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Binary Search function
int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// Generate sorted random array
void generate_sorted_array(int arr[], int size) {
    arr[0] = rand() % 10;
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i-1] + (rand() % 5 + 1);
    }
}

int main() {
    int size, target;
    printf("Enter how many random numbers to generate: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));
    generate_sorted_array(arr, size);

    printf("Generated sorted numbers:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter target value: ");
    scanf("%d", &target);

    clock_t start = clock();
    int result = binary_search(arr, size, target);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element not found\n");

    printf("Time taken for binary search: %f seconds\n", time_taken);

    free(arr);
    return 0;
}
