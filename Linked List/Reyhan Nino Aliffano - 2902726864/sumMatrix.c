#include <stdio.h>
#define gc getchar()


void showMatriks( int size, int arr[size+1][size+1]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}


void tambahMatrix(int size, int arr1[size+1][size+1], int arr2[size+1][size+1]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ",arr1[i][j]+arr2[i][j]);
        }
        printf("\n");
    }
}


int main (){
    int size = 0;
    scanf("%d",&size); gc;
    int arr1[size+1][size+1];
    int arr2[size+1][size+1];

    puts("Input elements in the first matrix : ");

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("element - [%d],[%d] : ",i, j);
            scanf("%d",&arr1[i][j]); gc;
        }
    }

    puts("Input elements in the second matriks : ");

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("element - [%d],[%d] : ", i, j);
            scanf("%d",&arr2[i][j]); gc;
        }
    }

    puts("The first matrix is:");
    showMatriks(size, arr1);

    puts("The Second matrix is:");
    showMatriks(size, arr2);

    puts("The Addition of two matrix is: ");
    tambahMatrix(size, arr1, arr2);

    




    return 0;
}