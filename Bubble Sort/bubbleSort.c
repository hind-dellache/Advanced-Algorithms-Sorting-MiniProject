#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NB_TESTS 5

void bubbleSort(int A[], int n) {
    int temp;

    for (int pass = 0; pass < n - 1; pass++) {
        for (int i = 0; i < n - 1; i++) {
            if (A[i] > A[i + 1]) {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
            }
        }
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
            bubbleSort(A, n);
            clock_t end = clock();

            totalTime += (double)(end - start) / CLOCKS_PER_SEC;
            free(A);
        }

        printf("BubbleSort | n = %d | avg time = %f seconds\n",
               n, totalTime / NB_TESTS);
    }

    return 0;
}
