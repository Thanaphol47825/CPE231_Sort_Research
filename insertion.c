#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, size);

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
