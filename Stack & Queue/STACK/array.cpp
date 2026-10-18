#include <stdio.h>
#define MAX 10
int arr[MAX];
int top = -1;

    void push(int value){
        if (top == MAX - 1){
            printf("Stack Penuh\n");
        }
        else{
            top++;
            arr[top] = value;
        }
    }

    void pop(){
        if (top == -1){
            printf("Stack underflow");
        }
        else{
            top--;
        }
    }


    void display(){
        for(int i = 0; i <= top; i++){
            printf("%d\n",arr[i]);
        }
    }

int main(){
    push(1);
    push(2);
    push(3);
    push(20);
    push(10);
    pop();
    display();





    return 0;
}