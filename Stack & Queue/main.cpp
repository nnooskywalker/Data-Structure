#include <stdio.h>
#include <stdlib.h>
#define MAX 6

int stackArr[MAX];
int top = -1;           //belum ada data

//top: -1
//Idx:  0  |  1  |   2   |  3  |  4  |  5  |  
//Value: mengembalikan value yang ingin dihapus

int isEmpty(){
    if (top == -1)
        return 1;

    return 0;
}

int isFull(){
    if (top == MAX-1)
        return 1;

    return 0;
}


void viewStack(){
    if (isEmpty){
        printf("Stack kosong!\n");
        return;
    }

    for (int i  = top; i>=0; i--){      //dari piring paling atas
        printf("%d ", stackArr[i]);
    }

}

void push(int data){
    if (isFull()){
        printf("Stack Overflow");
        return;
    }

    top += 1;
    stackArr[top] = data;
}

int pop(){
    int value;
    if (isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }

    value = stackArr[top];
    top = top-1;
    return value;
}

int size(){
    if (isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return top+1;
}

int peek(){
    if (isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }

    return stackArr[top];
}


int main () {
    push(5);
    push(6);
    push(9);
    push(20);

    viewStack();



    return 0;
}