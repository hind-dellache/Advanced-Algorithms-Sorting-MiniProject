#include <stdio.h>

// Function to apply Gnome Sort
void gnomeSort(int arr[], int n) {
    int index = 0;
    int temp;

    while (index < n) {
        if (index == 0) {
            index++;
        }
        if (arr[index] >= arr[index - 1]) {
            index++;
        } else {
            // Swap elements
            temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;

            index--;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 3, 2, 4, 1};
    int n = 5;

    printf("Array before sorting:\n");
    printArray(arr, n);

    gnomeSort(arr, n);

    printf("Array after sorting:\n");
    printArray(arr, n);

    return 0;
}
