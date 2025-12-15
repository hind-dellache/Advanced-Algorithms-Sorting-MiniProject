#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ---------- Swap two elements ---------- */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ---------- Partition function ---------- */
int partition(int tab[], int d, int f) {
    int pivot = tab[d];   // pivot element
    int i = f;
    int j = d;
    int x;

    while (j <= i) {
        while (j <= f && tab[j] <= pivot)
            j++;

        while (i >= d && tab[i] > pivot)
            i--;

        if (j < i) {
            x = tab[j];
            tab[j] = tab[i];
            tab[i] = x;
            j++;
            i--;
        }
    }
    return i;
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
        int *A = malloc(n * sizeof(int));

        fillRandom(A, n);

        clock_t start = clock();
        quickSort(A, 0, n - 1);
        clock_t end = clock();

        double time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("QuickSort | n = %d | time = %f seconds\n", n, time);

        free(A);
    }

    return 0;
}
