#include <stdio.h>
#include <stdlib.h>
void swap(int* m, int* n)
{
    int temp = *m;
    *m = *n;
    *n = temp;
}

int partition(int arr[], int l, int r)
{
    int p = arr[l];
    int i = l;
    int j = r+1;
    do{
        do{
            i++;
        }while(arr[i]<p);
        do{
            j--;
        }while(arr[j]>p);
        swap(&arr[i],&arr[j]);
    }while(i<j);
    swap(&arr[i],&arr[j]);
    swap(&arr[l],&arr[j]);
    return j;
}

void quicksort(int arr[],int l, int r)
{
    if(l<r){
        int p = partition(arr,l,r);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,r);
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
    quicksort(arr, 0,size-1);

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
