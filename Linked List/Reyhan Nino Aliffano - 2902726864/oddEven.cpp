#include <stdio.h>


void show(int arr[], int len){
    for(int i = 0; i < len; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int num = 0, k = 0, j = 0;

    scanf("%d",&num);
    int arr[num + 1];
    int odd[num + 1];
    int even[num + 1];


    for(int i = 0; i < num; i++){
        scanf("%d",&arr[i]);
    }



    for(int i = 0; i < num; i++){
        if (arr[i] % 2 == 0){
            even[k] = arr[i];
            k++;
        }
        else if (arr[i] % 2 != 0){
            odd[j] = arr[i];
            j++;
        }
    }

    printf("The even elements are:\n");
    show(even,k);

    printf("\nThe odd elements are:\n");
    show(odd, j);
    








    return 0;
}