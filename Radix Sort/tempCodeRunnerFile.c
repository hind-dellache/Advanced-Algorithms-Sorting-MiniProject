#include <stdio.h>
#include <stdlib.h>


// Function key
int key(int x, int i) {
    int divisor = 1;
    for(int j = 0; j < i; j++) {
        divisor *= 10;
    }
    return (x / divisor) % 10;
}

// Function SortAux
void SortAux(int T[], int n, int i) {
    int* output = (int*)malloc(n * sizeof(int)); 
    if(output == NULL) {
        printf("Error: memory allocation failed\n");
        return;
    }

    int count[10] = {0}; // count array for digits 0-9

    // Count occurrences of each digit
    for(int j = 0; j < n; j++) {
        count[key(T[j], i)]++;
    }

    // Cumulative count to get positions
    for(int j = 1; j < 10; j++) {
        count[j] += count[j-1];
    }

    // Build the output array (stable)
    for(int j = n-1; j >= 0; j--) {
        int d = key(T[j], i);
        output[count[d]-1] = T[j];
        count[d]--;
    }

   
    for(int j = 0; j < n; j++) {
        T[j] = output[j];
    }

    free(output); 
}


// Function RadixSort
void RadixSort(int T[], int n, int k) {
    for(int i = 0; i < k; i++) {
        SortAux(T, n, i);
    }
}


// Function to print array

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr[] = {141, 232, 45, 112, 143};
    int n = 5;      
    int k = 3;      

    printf("Array before sorting:\n");
    printArray(arr, n);

    RadixSort(arr, n, k); 

    printf("Array after sorting:\n");
    printArray(arr, n);

    return 0;
}
