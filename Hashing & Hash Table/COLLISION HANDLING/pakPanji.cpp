#include <stdio.h>
#include <stdlib.h>
#define  TABLE_SIZE 5

typedef struct dataItem{
    int data;
    int key;
}dataItem;

dataItem *hashArray[TABLE_SIZE];

dataItem *dummy;

int hashDivision(int key){
    return key % TABLE_SIZE;
}

void insert(int key, int data){
    dataItem *item = (dataItem*)malloc(sizeof(dataItem));
    item->data = data;
    item->key = key;


    int hashIndex = hashDivision(key);

    for(int i = 0; i < TABLE_SIZE; i++){
        int index = (hashIndex + i) % TABLE_SIZE;

        if(hashArray[index] == NULL || hashArray[index] == dummy){
            hashArray[index] = item;
            printf("Inserted at index %d\n",index+1);
            printf("Data %d\n", hashArray[index]->data);    
            return;
        }

    }
    printf("Table penuh, tidak dapat memasukkan data baru\n");

}

int main (){
    dummy = malloc(sizeof(dataItem));
    dummy->data = -1;
    dummy->key = -1;

    insert(1, 56);
    insert(1, 65);
    insert(1, 23);
    insert(1, 87);
    insert(1, 53);
    insert(1, 72);




    return 0;
}