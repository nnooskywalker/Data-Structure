#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
#define gc getchar()
typedef struct node{
    char name[100];
    char id[100];
    int key;
    struct node *next;
}node;

node *hashTable[SIZE];



void setHash(){
    for(int i = 0; i < SIZE; i++){
        hashTable[i] = NULL;
    }
}


int convertToKey(char name[]){
    int len = strlen(name);
    int key = 0;

    for(int i = 0; i < len; i++){
        key += name[i];
    }

    return key;
}

pin f halo

int hashFunction(int key){
    long long square = key * key;
    char str[20];

    //mid square
    sprintf(str,"%lld",square);
    int len = strlen(str);
    int mid = len / 2;
    int index = 0;

    if(len % 2 == 0){
        index = (str[mid-1] - '0')*10 + (str[mid] - '0');
    }
    else{
        index = (str[mid-1] - '0')*100 + (str[mid] - '0')*10 + (str[mid+1] - '0');
    }


    // rotating
    int right = 0;

        while(key > 0){
            right = key % 10;
            index = index * 10 + right;

            key/=10;
        }

    // folding
    return index % SIZE;
}



void validate(char userName[], char id[]){
    char saveName[105];
    char saveID[105];
    int count =0, k = 0;

    if (count == 0){
        strcpy(saveName[k],userName);
    }


}

void insert(int key, char * id, char *name){
    int k = 0;
    int index = hashFunction(key);

    node *newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->id,id);
    newNode->key = key;
    strcpy(newNode->name,name);

    if(hashTable[index] == NULL){
        hashTable[index] = newNode;
        printf("Baru diinsert bang\n");
        k++;
    }
    else{
        node *curr = hashTable[index];

        while(curr != NULL){
            curr = curr->next;
        }

        curr->next = newNode;
        printf("Udah masuk Chaining CIHUYYYY\n");
        k++;
    }


    if(k == SIZE){
        printf("Bang udah bang\n");
    }
}

void search(int key){
    int index = hashFunction(key);
    if (hashTable[index] == NULL){
        printf("Kosong");
        return;
    }
    
    node *curr = hashTable[index];

    while(curr != NULL){
        if(curr->key == key){
            printf("Nama : %s\n",curr->name);
            printf("ID : %s\n",curr->id);
            break;
        }
        curr = curr->next;
    }

    if (curr == NULL){
        printf("Data tidak ditemukan\n");
    }

}

void view(){
    puts("====View====");
    for(int i = 0; i  < SIZE; i++){
        printf("Data %d :\n",i+1);

        node *curr = hashTable[i];

        if(curr == NULL){
            printf("kosong\n");
        }
        else{
            printf("%s;%s\n",curr->name,curr->id);
        }
    }
}

void deleteIndex(int key){
    int index = hashFunction(key);
    node *curr = hashTable[index];
    node *prev = NULL;

    if(hashTable[index] == NULL){
        printf("Data tidak ditemukan\n");
    }

    while(curr != NULL){
        if(curr->key == key){
            if(prev == NULL){
                hashTable[index] = curr->next;
            }
            else{
                prev->next = curr->next;
            }
            free(prev);
            printf("Data sucesfully deleted !\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }



}



void menu(){
    setHash();
    char userName[100], id[100];
    char searchName[100];
    int choose = 0, key = 0, k = 0;
    int save[100];

    while(choose != 5){
        puts("=======Finding U=======");
        puts("1. Insert");
        puts("2. Search");
        puts("3. View");
        puts("4. Delete");
        puts("5. Exit");
        printf(">> ");
        scanf("%d",&choose); gc;

        switch(choose){
            case 1:
              //  while(validate != 0){
                    printf("Username : ");
                    scanf("%s",userName);
                    printf("ID : ");
                    scanf("%s",id);
                    key = convertToKey(userName);
            //        validate(key);
            //    }
                insert(key,id, userName);
                printf("Insert Sucesfully\n");
                break;
            case 2:
                printf("Search by Name (key) : ");
                scanf("%s",searchName);
                key = convertToKey(searchName);
                search(key);
                break;
            case 3:
                view();
                break;
            case 4:
                printf("Search by Name (key) : ");
                scanf("%s",searchName);
                key = convertToKey(searchName);
                deleteIndex(key);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid\n");
                break;
        }
    }
}
int main (){
    menu();
 



    return 0;
}

