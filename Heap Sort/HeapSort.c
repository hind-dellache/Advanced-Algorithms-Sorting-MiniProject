#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;       //  largest as root
    int left = 2*i + 1;    
    int right = 2*i + 2;   

    // If left child is larger than root
    if(left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if(right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Build a max-heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for(int i = n-1; i >= 0; i--) {
        swap(&arr[0], &arr[i]); // Move current root to end
        heapify(arr, i, 0);     // Heapify the reduced heap
    }
}

// print the array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr[] = {16, 10, 8, 11, 5, 6, 9, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorting:\n");
    printArray(arr, n);

    heapSort(arr, n); // Sort the array using Heap Sort

    printf("Array after sorting:\n");
    printArray(arr, n);

    return 0;
}
