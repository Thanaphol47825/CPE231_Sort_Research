
#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int r, int m)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int i=0,j=0,k=0;
    int* temp = malloc(sizeof(int)*(n1+n2));
    while(i<n1 && j<n2)
    {
        if(arr[l+i] < arr[m+1+j]){
            temp[k++] = arr[l+i];
            i++;
        }
        else{
            temp[k++] = arr[m+1+j];
            j++;
        }
    }
    while (i < n1) {
    temp[k++] = arr[l + i];
    i++;
}
while (j < n2) {
    temp[k++] = arr[m + 1 + j];
    j++;
}
    for(i=0 ; i<k ; i++){
        arr[l+i] = temp[i];
    }
    free(temp);
}

void mergesort1(int arr[],int l, int r)
{
    if(l<r){
        int m = (l+r)/2;
        mergesort1(arr,l,m);
        mergesort1(arr,m+1,r);
        merge(arr,l,r,m);
    }
}

int main() {
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

    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        perror("Memory allocation failed");
        fclose(inputFile);
        return 1;
    }

    // Read the array elements from the file
    for (int i = 0; i < size; i++) {
        if (fscanf(inputFile, "%d", &arr[i]) != 1) {
            perror("Unable to read an integer from the input file");
            free(arr);
            fclose(inputFile);
            return 1;
        }
    }

    fclose(inputFile);

    // Sort the array using merge sort
    mergesort1(arr, 0, size - 1);

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

