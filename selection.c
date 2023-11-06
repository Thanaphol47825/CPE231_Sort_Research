#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
 
        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
    // Open the input file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Unable to open the file");
        return 1;
    }

    int size;
    fscanf(file, "%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    // Read the array elements from the file
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    // Sort the array using bubble sort
    selectionSort(arr, size);

    // Open the output file
    file = fopen("output.txt", "w");
    if (file == NULL) {
        perror("Unable to create the output file");
        free(arr);
        return 1;
    }

    // Write the sorted array to the output file
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);

    free(arr);
    return 0;
}
