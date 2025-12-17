#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function key
int key(int x, int i) {
    int divisor = 1;
    for (int j = 0; j < i; j++) {
        divisor *= 10;
    }
    return (x / divisor) % 10;
}

// Function SortAux (Counting Sort by digit i)
void SortAux(int T[], int n, int i) {
    int *output = (int *)malloc(n * sizeof(int));
    if (output == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    int count[10] = {0};

    // Count occurrences
    for (int j = 0; j < n; j++) {
        count[key(T[j], i)]++;
    }

    // Cumulative count
    for (int j = 1; j < 10; j++) {
        count[j] += count[j - 1];
    }

    // Build output array (stable)
    for (int j = n - 1; j >= 0; j--) {
        int d = key(T[j], i);
        output[count[d] - 1] = T[j];
        count[d]--;
    }

    // Copy back
    for (int j = 0; j < n; j++) {
        T[j] = output[j];
    }

    free(output);
}

// Radix Sort
void RadixSort(int T[], int n, int k) {
    for (int i = 0; i < k; i++) {
        SortAux(T, n, i);
    }
}

// Fill array with random integers in [0, 10^k - 1]
void fillRandom(int T[], int n, int k) {
    int max = 1;
    for (int i = 0; i < k; i++)
        max *= 10;

    for (int i = 0; i < n; i++)
        T[i] = rand() % max;
}

int main() {
    int sizes[] = {1000, 2000, 4000, 8000};
    int nb_tests = 4;
    int k = 3; 

    srand(time(NULL));

    for (int t = 0; t < nb_tests; t++) {
        int n = sizes[t];
        int *T = (int *)malloc(n * sizeof(int));

        fillRandom(T, n, k);

        clock_t start = clock();
        RadixSort(T, n, k);
        clock_t end = clock();

        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

        printf("n = %d | Execution time = %f seconds\n", n, time_spent);

        free(T);
    }

    return 0;
}
