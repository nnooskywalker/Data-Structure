#include <stdio.h>
#define gc getchar()


int main (){
    int r = 0, c = 0;
    scanf("%d %d",&r,&c); gc;
    int arr[r+1][c+1];

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("Element -[%d],[%d]: ",i,j);
            scanf("%d",&arr[i][j]); gc;
        }
    }

    puts("The Matrix is :");
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }





    return 0;
}