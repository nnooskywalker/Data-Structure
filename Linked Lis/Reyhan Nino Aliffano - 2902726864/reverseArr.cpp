#include <stdio.h>




void showArr(int arr[], int len){
    for(int i = 0; i < len; i++){
        printf("%d ",arr[i]);
    }
}

void reverseArr(int arr[], int len){
    for(int i = len-1; i >= 0; i--){
        printf("%d ",arr[i]);
    }
}

int main (){
    int num = 0;

    scanf("%d",&num);
    int arr[num + 1];

    for(int i = 0; i < num; i++){
        scanf("%d",&arr[i]);
    }

    puts("The values store into the array are :");
    showArr(arr,num);

    puts("\nThe values store into the array in reverse are : ");
    reverseArr(arr, num);



    






   





    return 0;
}