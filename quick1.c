#include <stdio.h>
#include <stdlib.h>

void swap(int *m, int *n)
{
    int temp = *m;
    *m = *n;
    *n = temp;
}

int partition(int arr[], int l, int r)
{
    int p = arr[l];
    int i = l;
    int j = r + 1;
    do
    {
        do
        {
            i++;
        } while (arr[i] < p);
        do
        {
            j--;
        } while (arr[j] > p);
        swap(&arr[i], &arr[j]);
    } while (i < j);
    swap(&arr[i], &arr[j]);
    swap(&arr[l], &arr[j]);
    return j;
}

void quicksort1(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quicksort1(arr, l, p - 1);
        quicksort1(arr, p + 1, r);
    }
}

int main()
{
   // Open the input file
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Unable to open the input file");
        return 1;
    }

    int size;
    if (fscanf(inputFile, "%d", &size) != 1) {
        perror("Unable to read size from the input file");
        fclose(inputFile);
        return 1;
    }

    int *arr = (int *)malloc((size+10) * sizeof(int));
    
    // Check if memory has been allocated successfully
    if (arr == NULL) {
        perror("Memory allocation failed");
        fclose(inputFile);
        return 1;
    }
    printf("Allocated memory for %d integers.\n", size);

    // Read the array elements from the file
    for (int i = 0; i < size; i++) {
        // printf("i = %d\n", i);
        if (fscanf(inputFile, "%d", &arr[i]) != 1) {
            perror("Unable to read an integer from the input file");
            printf("Unable to read an integer from the input file");
            free(arr);
            fclose(inputFile);
            return 1;
        }
    }

    fclose(inputFile);

    // Sort the array using quick sort
    quicksort1(arr, 0, size - 1);

    // Open the output file
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Unable to create the output file");
        free(arr);
        return 1;
    }

    // Write the sorted array to the output file
    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }

    fclose(outputFile);
    return 0;
}
