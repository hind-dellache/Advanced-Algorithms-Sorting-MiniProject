#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ---------- Partition function ---------- */
int partition(int tab[], int d, int f) {
    int pivot = tab[d];   // pivot element
    int i = d - 1;        // index moving from left to right
    int j = f + 1;        // index moving from right to left
    int temp;

    while (1) {
        /* Move i until an element >= pivot is found */
        do {
            i++;
        } while (tab[i] < pivot);

        /* Move j until an element <= pivot is found */
        do {
            j--;
        } while (tab[j] > pivot);

        /* If indices cross, partitioning is finished */
        if (i >= j)
            return j;

        /* Swap elements tab[i] and tab[j] */
        temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }
}

/* ---------- Quick Sort ---------- */
void quickSort(int tab[], int p, int r) {
    int q;
    if (p < r) {
        q = partition(tab, p, r);
        quickSort(tab, p, q);
        quickSort(tab, q + 1, r);
    }
}

/* ---------- Fill array with random values ---------- */
void fillRandom(int A[], int n) {
    for (int i = 0; i < n; i++)
        A[i] = rand();
}

/* ---------- Main ---------- */
int main() {
    int sizes[] = {1000, 2000, 4000, 8000, 16000};
    int nbSizes = 5;

    /* Initialize random number generator */
    srand(time(NULL));

    /* Loop over different array sizes */
    for (int s = 0; s < nbSizes; s++) {
        int n = sizes[s];
        int *A = malloc(n * sizeof(int));

        fillRandom(A, n);

        /* Measure execution time */
        clock_t start = clock();
        quickSort(A, 0, n - 1);
        clock_t end = clock();

        double time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("QuickSort | n = %d | time = %f seconds\n", n, time);

        free(A);
    }

    return 0;
}
