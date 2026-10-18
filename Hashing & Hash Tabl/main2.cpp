#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
typedef struct node{
    int key;
    int data;
    struct node *next;
}node;

void hashFunction(int key){
    int temp = 0;

    while(key > 0){
        temp += key % 100;

        key/=100;
    }

    return temp % SIZE;
}

    node *hashTable[SIZE];


    void setTable(){
        for(int i = 0; i < SIZE; i++){
            hashTable[i] = NULL;
        }
    }

    node *createNode(int key, int data){
        node *newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->key = key;
        newNode->next = NULL;

        return newNode;
    }

    void insert(int data, int key){
        node *newNode = createNode(key, data);
        int index = hashFunction(key);

        node *curr = hashTable[index];

        if (curr == NULL){
            curr = newNode;
        }
        else{
            while(curr->next != NULL){
                curr = curr->next;
            }

            curr->next = newNode;
        }
    }


    void delete(int key){
        int index = hashFunction(key);
        node *curr = hashTable[index];
        node *prev = NULL;

        while(curr != NULL){
            if (curr->key == key){
                if (prev == NULL){
                    hashTable[index] = curr->next;
                }
                else{
                    prev->next = curr->next
                }
                free(curr);
                return;
            }
            
            prev = curr;
            curr = curr->next;
        }
    }

int main(){
    setTable();



}