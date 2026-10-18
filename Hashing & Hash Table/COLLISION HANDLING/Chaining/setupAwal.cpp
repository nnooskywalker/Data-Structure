#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct node{
    int key;
    int data;
    struct node*next;

}node;

node *hashTable[SIZE];

void initHash(){ //set hashTable
    for(int i = 0; i < SIZE; i++){
        hashTable[i] = NULL;
    }
}

int hashFunction(int key){
    return key % SIZE; // use division method
}


int main (){

}