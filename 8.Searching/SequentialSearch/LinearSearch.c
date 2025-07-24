// sequential_search_random.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sequential_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
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
    printf("Generated numbers:\n");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;  // random number 0 to 99999
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter target value: ");
    scanf("%d", &target);

    clock_t start = clock();
    int result = sequential_search(arr, size, target);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element not found\n");

    printf("Time taken for sequential search: %f seconds\n", time_taken);

    free(arr);
    return 0;
}
