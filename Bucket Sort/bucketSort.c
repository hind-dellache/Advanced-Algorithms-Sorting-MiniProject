#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Node {
    float value;
    struct Node *next;
} Node;


void insertionSortList(Node **head, float value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->value >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->value < value)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
}


void bucketSort(float A[], int n) {
    Node **B = malloc(n * sizeof(Node *));

    for (int i = 0; i < n; i++)
        B[i] = NULL;

    /* Distribute elements into buckets */
    for (int i = 0; i < n; i++) {
        int index = (int)(n * A[i]);
        insertionSortList(&B[index], A[i]);
    }

    /* Concatenate buckets */
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node *current = B[i];
        while (current != NULL) {
            A[k++] = current->value;
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(B);
}

void fillRandom(float A[], int n) {
    for (int i = 0; i < n; i++)
        A[i] = (float)rand() / RAND_MAX;
}

int main() {
    int sizes[] = {1000, 2000, 4000, 8000};
    int nbSizes = 4;

    srand(time(NULL));

    for (int s = 0; s < nbSizes; s++) {
        int n = sizes[s];
        float *A = malloc(n * sizeof(float));

        fillRandom(A, n);

        clock_t start = clock();
        bucketSort(A, n);
        clock_t end = clock();

        double time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("BucketSort | n = %d | time = %f seconds\n", n, time);

        free(A);
    }

    return 0;
}
