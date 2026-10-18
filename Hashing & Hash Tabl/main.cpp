#include <stdio.h>
#define SIZE 100
#define EMPTY 0
#define OCCUPIED 1
#define DELETED 2

typedef struct node{
    int key;
    int status;
    char name[100];
}node;

node hashTable[SIZE];

void setHash(){
    for(int i = 0; i < SIZE; i++){
        hashTable[i] = EMPTY;
    }
}

void hashFunction(int key){
    return key % SIZE;
}

void insertData(node insert){
    int index = hashFunction(insert.key);

    while(hashTable[index] == OCCUPIED){
        index = (index + 1) % SIZE;
    }

    hashTable[index].key = insert.key;
    hashTable[index].name = insert.name;
    hashTable[index].status = OCCUPIED;
}

void search(node insert){
    int index = hashFunction(insert.key);
    int start = index;

    while(hashTable[index].status != EMPTY){
        if(hashTable[index].key == insert.key){
            printf("Nama : %s",hashTable[index].key);
            return;
        }

        index = (index + 1) %SIZE;

        if(start == index){
            printf("Data Not Found\n");
            break;
        }
    }


}

void show(){
    for(int i = 0; i < SIZE; i++){
        printf("Index - %d :\n",i);

        if (hashTable[i].status == EMPTY){
            printf("Kosong\n");
        }
        else{
            printf("Nama : %s\n",hashTable[i].name);
        }
    }
}

int main(){




    return 0;
}