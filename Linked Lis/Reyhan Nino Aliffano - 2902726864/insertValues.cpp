#include <stdio.h>
#define gc getchar()

void show(int arr[], int len){
    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main (){
    int num = 0, val = 0, p = 0;

    scanf("%d", &num);
    int arr[num + 1];   

    for(int i = 0; i < num; i++){
        scanf("%d", &arr[i]); gc;
    }

    printf("The values store into the array are:\n");
    show(arr, num);

    printf("Input the value to be inserted:\n");
    scanf("%d", &val); gc;

    printf("Input the position where the value to be inserted:\n");
    scanf("%d", &p); gc;

  
    for(int i = num; i >= p; i--){
        arr[i] = arr[i - 1];
    }

  
    arr[p - 1] = val;

    printf("The current list of the Array:\n");
    show(arr, num + 1);

    return 0;
}
