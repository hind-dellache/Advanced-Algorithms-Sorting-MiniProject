#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Gnome Sort for real numbers
void gnomeSort(double arr[], int n) {
    int index = 0;
    double temp;

    while (index < n) {
        if (index == 0) {
            index++;
        }
        if (arr[index] >= arr[index - 1]) {
            index++;
        } else {
            // Swap
            temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index--;
        }
    }
}

// Fill array with random real numbers in [0,1[
void fillRandom(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (double)rand() / RAND_MAX;
    }
}

int main() {
    int sizes[] = {1000, 2000, 4000, 8000};
    int nb_tests = 4;

    srand(time(NULL));

    for (int t = 0; t < nb_tests; t++) {
        int n = sizes[t];
        double *arr = (double *)malloc(n * sizeof(double));

        fillRandom(arr, n);

        clock_t start = clock();
        gnomeSort(arr, n);
        clock_t end = clock();

        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

        printf("n = %d | Execution time = %f seconds\n", n, time_spent);

        free(arr);
    }

    return 0;
}
