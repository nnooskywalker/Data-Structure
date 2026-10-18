#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

struct node{
    char nama[100];
    char nim[100];
    char jurusan[30];

    struct node *next;
};
int count = 0;


struct node *createNode(char *nama, char *nim, char *jurusan){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->nama, nama);
    strcpy(newNode->nim, nim);
    strcpy(newNode->jurusan, jurusan);

    newNode->next = NULL;
    return newNode;
}


struct node *hashTable[SIZE];

int hashIndex(char *nim){
    int jumlah = 0;

    for(int i = 0; i < strlen(nim); i++){
        jumlah += nim[i];
    }

    return jumlah % SIZE;
}


void insertNode(char *nama, char *nim, char *jurusan){
    int index = hashIndex(nim);
    struct node *curr = hashTable[index];

    if (curr == 0){
        hashTable[index] = createNode(nama, nim, jurusan);
    }

    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = createNode(nama, nim, jurusan);
}

void printData(){
    if (count == 0){
        printf("No Data\n");
        return;
    }

    for(int i = 0; i < SIZE; i++){
        if (!hashTable[i]){
            printf("-\n");
        }
        else{
            struct node *curr = hashTable[i];

            while(curr != NULL){
                printf("(%s) %s - %s", curr->nim, curr->nama, curr->jurusan);
                if (curr->next){
                    printf("->");
                }

            }
        }
    }
}

void pop(char *nim){
    int index = hashIndex(nim);
    struct node *prev = NULL;
    struct node *curr = hashTable[index];

    while(curr != NULL){

        if (strcmp(curr->nim, nim)){
            if (curr == NULL){
                hashTable[index] = curr->next;
            }
            else{
                prev->next = curr->next;
            }
            free(curr);
            count--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Data Not Found\n");

}



int main(){
    insertNode("Jevon","123456","Compscii");
    
    printf("%d",hashIndex("123456789"));


    return 0;
}
