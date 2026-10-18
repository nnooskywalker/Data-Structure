#include <stdio.h>
#include <sdlib.h>
#include <string.h>
#define SIZE 100

struct user{
    char nama[30];
    char password[30];

    struct user *next;
}

struct user *createUser(char *nama, char *password){
    struct user *newData = (struct user*)malloc(sizeof(user));
}

void printTable(){

    for(int i = 0; i < SIZE; i++){
        if(hash_table[i] == NULL){
            printf("%d - No Data\n", i);
        }
        else{
            struct user *temp = hash
        }
    }
}


void pop(char *nama){
    int hash_Value = hash(nama);
    struct user *temp = hash_table[hash_value % SIZE];


    if(temp == NULL){
        printf("No Data to bedeleted\n");
        return;
    }

    if(temp->next == NULL && strcmp(temp->nama, nama) == 0){
        free(temp);
        hash_table[hash_value%size] = NULL;
    }

    while(temp != NULL){
        if(strcmp(temp->nama, nama) == 0){
            prev->next = temp->next;
            free(temp);
        }
        temp =temp;
        temp = temp->next;

    }

    pritnf("No data to be deleted")
}