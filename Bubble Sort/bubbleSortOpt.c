#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NB_TESTS 5

void bubbleSortOpt(int A[], int n) {
    bool change = true;
    int m = n - 1, temp;

    while (change) {
        change = false;
        for (int i = 0; i < m; i++) {
            if (A[i] > A[i + 1]) {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                change = true;
            }
        }
        m--;
    }
}

void fillRandom(int A[], int n) {
    for (int i = 0; i < n; i++)
        A[i] = rand();
}

int main() {
    int sizes[] = {1000, 2000, 4000, 8000, 16000};
    int nbSizes = 5;

    srand(time(NULL));

    for (int s = 0; s < nbSizes; s++) {
        int n = sizes[s];
        double totalTime = 0.0;

        for (int t = 0; t < NB_TESTS; t++) {
            int *A = malloc(n * sizeof(int));
            fillRandom(A, n);

            clock_t start = clock();
            bubbleSortOpt(A, n);
            clock_t end = clock();

            totalTime += (double)(end - start) / CLOCKS_PER_SEC;
            free(A);
        }

        printf("BubbleSortOpt | n = %d | avg time = %f seconds\n",
               n, totalTime / NB_TESTS);
    }

    return 0;
}
