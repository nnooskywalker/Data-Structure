#include <stdio.h>
#define gc getchar()

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findPivot(int arr[], int left, int right){
    int pivot = arr[right];
    int oren = left - 1;

    for(int i = left; i < right; i++){
        if (arr[i] > pivot){
            oren++;
            swap(&arr[oren],&arr[i]);
        }
    }
    swap(&arr[oren+1],&arr[right]);


    return oren + 1;
}


void quick(int arr[], int left, int right){
    if (left < right){
        int pivotIndex = findPivot(arr, left, right);

        quick(arr, left, pivotIndex-1);
        quick(arr,pivotIndex+1, right);
    }
}

void viewSort(int arr[], int len){
    for(int i = 0; i < len; i++){
        printf("%d ",arr[i]);
    }
}

int main (){
    int size = 0;
    scanf("%d",&size); 
    int arr[size + 1];

    for(int i = 0; i < size; i++){
        scanf("%d",&arr[i]); gc;
    }

    quick(arr,0, size - 1);
    

    printf("The Second Largest Element in the array is: %d\n",arr[1]);






    return 0;
}