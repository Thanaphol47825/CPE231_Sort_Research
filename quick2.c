#include <stdlib.h>
#include <stdio.h>

// function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high)
{
    int p = array[low];
    int i = low, j = high + 1;
    while (1)
    {
        do
        {
            i++;
        } while (array[i] < p && i < high);
        do
        {
            j--;
        } while (array[j] > p);

        if (i >= j)
        {
            swap(&array[low], &array[j]);
            return j;
        }
        swap(&array[i], &array[j]);
    }
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

// function to print array elements
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// main function
int main()
{
    // Open the input file
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        perror("Unable to open the input file");
        return 1;
    }

    int size;
    if (fscanf(inputFile, "%d", &size) != 1)
    {
        perror("Unable to read size from the input file");
        fclose(inputFile);
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL)
    {
        perror("Memory allocation failed");
        fclose(inputFile);
        return 1;
    }

    // Read the array elements from the file
    for (int i = 0; i < size; i++)
    {
        if (fscanf(inputFile, "%d", &arr[i]) != 1)
        {
            perror("Unable to read an integer from the input file");
            free(arr);
            fclose(inputFile);
            return 1;
        }
    }

    fclose(inputFile);

    // Sort the array using merge sort
    quickSort(arr, 0, size - 1);

    // Open the output file
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        perror("Unable to create the output file");
        free(arr);
        return 1;
    }

    // Write the sorted array to the output file
    for (int i = 0; i < size; i++)
    {
        fprintf(outputFile, "%d ", arr[i]);
    }

    fclose(outputFile);
    return 0;
}