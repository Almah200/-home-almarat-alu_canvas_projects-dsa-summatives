#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Merge function for merging two subarrays
void merge(char** arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    char** L = (char**)malloc(n1 * sizeof(char*));
    char** R = (char**)malloc(n2 * sizeof(char*));

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free temporary arrays
    free(L);
    free(R);
}

// Merge Sort function
void mergeSort(char** arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
  clock_t start_time = clock();
    // Example array of names
    char* names[] = {"John", "Alice", "Bob", "Eve", "Charlie", "Denis", "Almarat", "Kevin", "Said", "Amin"};

    // Calculate the size of the array
    int size = sizeof(names) / sizeof(names[0]);

    // Print the original array
    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%s ", names[i]);
    }
    printf("\n");

    // Sort the array using merge sort
    mergeSort(names, 0, size - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%s ", names[i]);
    }
    printf("\n");

    clock_t end_time = clock();

    // Calculate the running time in seconds
    double running_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Print the running time
    printf("Running Time: %f seconds\n", running_time);


    return 0;
}