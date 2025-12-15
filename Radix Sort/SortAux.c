#include <stdlib.h>
#include <stdio.h>

void SortAux(int T[], int n, int i) {
    int* output = (int*)malloc(n * sizeof(int)); 
    if(output == NULL) { 
        printf("Error: memory allocation failed\n");
        return;
    }

    int count[10] = {0}; // count array for digits 0-9

    // count occurrences of each digit
    for(int j = 0; j < n; j++) {
        count[key(T[j], i)]++;
    }

    // cumulative count
    for(int j = 1; j < 10; j++) {
        count[j] += count[j-1];
    }

    // build output array (stable sort)
    for(int j = n-1; j >= 0; j--) {
        int d = key(T[j], i);
        output[count[d]-1] = T[j];
        count[d]--;
    }

    //  copy output back to original array
    for(int j = 0; j < n; j++) {
        T[j] = output[j];
    }

    free(output); 
}
