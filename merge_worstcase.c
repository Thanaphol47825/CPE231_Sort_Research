#include<stdio.h>
#include<stdlib.h>

void gen_worstcase(int* arr, int l, int r) {
    if (l == r) {
        arr[l] = l + 1;
        return;
    }
    int mid = (l + r) / 2;
    gen_worstcase(arr, l, mid);
    gen_worstcase(arr, mid + 1, r);
    for (int i = l; i <= mid; i++) {
        arr[i] = i + mid + 2 - l;
    }
    for (int i = mid + 1; i <= r; i++) {
        arr[i] = r + mid + 1 - i;
    }
}

int main(){

    FILE* fp = fopen("input.txt","r"); //input sorted data
    int num=0;
    fscanf(fp,"%d\n",&num);
    int* arr = malloc(sizeof(int)*num);
    for(int i=0 ; i<num ; i++)
    {
        fscanf(fp,"%d ",&arr[i]);
    }
    fclose(fp);
    for(int i=0 ; i<num ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    gen_worstcase(arr,0,num-1);
    for(int i=0 ; i<num ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}