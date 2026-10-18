#include <stdio.h>
#define gc getchar()

void showMatriks(int size, int arr[size][size]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int size;
    scanf("%d", &size); gc;

    int arr[size][size];
    int saveRow[size];
    int saveCol[size];

    puts("Input elements in the matrix:");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("element-[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // sum row
    for(int i = 0; i < size; i++){
        int sumRow = 0;
        for(int j = 0; j < size; j++){
            sumRow += arr[i][j];
        }
        saveRow[i] = sumRow;
    }

    // sum col
    for(int j = 0; j < size; j++){
        int sumCol = 0;
        for(int i = 0; i < size; i++){
            sumCol += arr[i][j];
        }
        saveCol[j] = sumCol;
    }

    puts("The matrix is:");
    showMatriks(size, arr);

    for(int i = 0; i < size; i++){
        printf("Baris ke-%d : %d\n", i+1, saveRow[i]);
    }

    for(int j = 0; j < size; j++){
        printf("Kolom ke-%d : %d\n", j+1, saveCol[j]);
    }

    return 0;
}
