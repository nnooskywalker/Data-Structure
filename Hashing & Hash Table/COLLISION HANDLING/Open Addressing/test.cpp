#include <stdio.h>
#define SIZE 100
#define EMPTY -1;
#define DELETED -2;

int hashTable[SIZE];

int hashFunction(int key){
    return key % SIZE;
}

void initHash(){
    for(int i = 0; i < SIZE; i++){
        hashTable[i] = EMPTY;
    }
}


void insert(int key){
    int index = hashFunction(key);

    while(hashTable[index] != EMPTY && hashTable[index] != DELETED){

        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;

}

void search(int key){
    int index = hashFunction(key);
    int start = index;


    while(hashTable[index] != EMPTY){
        if (hashTable[index] == key){
            return 1;
        }

        index = (index + 1) % SIZE;


        if(hashTable[index] == start){
            break;
        }
    }


    return 0;

}

void delete(int key){
    int index = hashFunction(index);
    int start = index;

    while(hashTable[index] != NULL){
        if (hashTable[index] == key){
            hashTable[index] = deleted;
            return;
        }
        index = index + 1 % SIZE;

        if(hashTable[index] == start){
            break;
        }
    }
}

int main(){



    return 0;
}