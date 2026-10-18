#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
//Linear Probing

//Key -> Value
struct user{
    char nama[30];
    char password[30];
};

struct user *hashTable[10];

int hash (char *input){
    int hash_value = 0;

    for(int i = 0; i < strlen(input); i++){
        hash_value += input[i];
    }

    return hash_value % SIZE;
}

void insert_node(char *nama, char *pw){
    int hash_value = hash(nama);
    int temp_idx = hash_value;
    int count = 0;

    //check penuh atau tidak
    if (count == SIZE){
        printf("Hash Table Penuh\n");
        return;
    }

    while(hashTable[temp_idx] != NULL){
        temp[idx] = (hash_value + 1) % SIZE;
    }
    hashTable[temp_idx] = create_user(nama, pw);
    count++;
}

struct user * create_user(char *nama, char *password){
    struct user * new_data = (struct user*)malloc(sizeof(struct user));
    strcpy(new_data->nama, nama);
    strcpy(new_data->password,password);
    return new_data;
}

void print(){
    for(int i = 0; i <SIZE; i++){
        if(hashTable[i] != NULL){
            printf("%d - %s, %s\n",i, hashTable[i]->nama, hashTable[i]->password);
        }
        else{
            printf("%d - no data\n",i);
        }
    }
}

int search(char *nama){
    if (count == 0){
        printf("No Data found\n");
        return -1;
    }

    int hash_value = hash(nama);
    int temp_idx = hash_value % SIZE;

    do{ //kalau tidak null dan match
        if(hashTable[temp_idx] == NULL && strmp(nama, hashTable[temp_idx]->nama) == 0){
            return temp_idx;
        }
        //majukan index
        temp_idx = (temp_idx + 1) % SIZE;

    }while(temp_idx != hash_value % SIZE);

    printf("No Data Foudnd\n");
    return -1;
}

void pop(char *nama){
    int index = search(nama);

    free(hash_table[index]);
    hashTable[index] = NULL;
}


int main(){
    insert_node("Jevon","Joevon123");
    insert_node("Louis","Louis82883");
    insert_node("Rico","rico123") ;
    



    return 0;
}