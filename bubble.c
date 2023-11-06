#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
// Function to perform bubble sort
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    // Open the input file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        perror("Unable to open the file");
        return 1;
    }

    int size;
    fscanf(file, "%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL)
    {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    // Read the array elements from the file
    for (int i = 0; i < size; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    // Sort the array using bubble sort
    bubbleSort(arr, size);

    // Open the output file
    file = fopen("output.txt", "w");
    if (file == NULL)
    {
        perror("Unable to create the output file");
        free(arr);
        return 1;
    }

    // Write the sorted array to the output file
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);

    free(arr);
    return 0;
}
