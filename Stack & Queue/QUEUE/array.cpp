#include <stdio.h>
#define MAX 10
int arr[MAX];
int front = -1;
int rear = -1;

    void enqueue(int value){
        if (rear == MAX-1){
            printf("Array Penuh");
        }
        else{
            if (front == -1) front = 0;
            rear++;
            arr[rear] = value;
        }
    }


    void dequeu(){
        if (front == -1 || front > rear){
            printf("Queue underflow\n");
        }
        else{
            front++;
        }
    }
int main(){





    return 0;
}