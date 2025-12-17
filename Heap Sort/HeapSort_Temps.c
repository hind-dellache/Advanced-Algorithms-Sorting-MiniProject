#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Fill array with random integers
void fillRandom(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand();
}

int main() {
    int sizes[] = {1000, 2000, 4000, 8000};
    int nb_tests = 4;

    srand(time(NULL));

    for (int t = 0; t < nb_tests; t++) {
        int n = sizes[t];
        int *arr = (int *)malloc(n * sizeof(int));

        fillRandom(arr, n);

        clock_t start = clock();
        heapSort(arr, n);
        clock_t end = clock();

        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

        printf("n = %d | Execution time = %f seconds\n", n, time_spent);

        free(arr);
    }

    return 0;
}
