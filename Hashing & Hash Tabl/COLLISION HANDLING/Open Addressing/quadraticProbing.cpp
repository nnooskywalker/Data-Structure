#include <stdio.h>
#include <stdlib.h>
#define  TABLE_SIZE 100
#define EMPTY 0
#define OCCUPIED 1
#define DELETED 2

typedef struct{
    int key;
    int data;
    int status;
}mahasiswa;
mahasiswa hashTable[TABLE_SIZE];



int hashFunction(int key){
    int right = 0;
    int index = 0;

    while(key > 0){
        right = key % 10;
        index = index*10 + right;

        key/= 10;
    }

    return index % TABLE_SIZE;
}

// set Hash Table
void fillTable(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashTable[i].status = EMPTY;
    }
}

// insert data
void insert(mahasiswa mhs){
    int hash = hashFunction(mhs.key);
    int index = 0;

    for(int i = 0; i < TABLE_SIZE; i++){
        index = (hash + i * i) % TABLE_SIZE;

        if (hashTable[index].status == EMPTY || hashTable[index].status == DELETED){
            hashTable[index].key = mhs.key;
            hashTable[index].data = mhs.data;
            hashTable[index].status = OCCUPIED;
            return;
        }
    }

    printf("Table penuh\n");
}

// delete data
void deleteData(mahasiswa mhs){
    int hash = hashFunction(mhs.key);
    int index = 0;

    for(int i = 0; i < TABLE_SIZE ; i++){
        index = (hash + i*i) % TABLE_SIZE;

        if(hashTable[index].status == EMPTY){
            //key tidak ada
            printf("Not Found\n");
            return;
        }

        if (hashTable[index].status == OCCUPIED && hashTable[index].key == mhs.key){
            hashTable[index].status = DELETED;
            return;
        }
    }

    printf("Not Found\n");
}

//searching
void search(mahasiswa mhs){
    int hash = hashFunction(mhs.key);
    int index = 0;

    for(int i = 0; i < TABLE_SIZE; i++){
        index = (hash + i*i) % TABLE_SIZE;

        if (hashTable[index].status == EMPTY){
            printf("Data Not Found\n");
            return;
        }

        if (hashTable[index].status == OCCUPIED && hashTable[index].key == mhs.key){
            printf("Data found at index %d\n",i);
            return;
        }

    }

    printf("Data Not Found\n");
}

//display data
void display(){
   for(int i = 0; i < TABLE_SIZE; i++){
    if(hashTable[i].status == EMPTY){
        printf("Index %d : Empty\n",i);
    }
    else if(hashTable[i].status == DELETED){
        printf("Index %d : DELETED\n",i);
    }
    else{
        printf("Index %d : key = %d, data = %d",i, hashTable[i].key, hashTable[i].data);
      
    }
   }
}


int main (){





    return 0;
}