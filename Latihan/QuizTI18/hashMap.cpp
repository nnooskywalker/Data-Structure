#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define gc getchar()
#define MAX 200
#define EMPTY 0
#define FULL 1
#define DELETED 2

typedef struct{
    int key;
    char fruit[100];
    int value;
    int status;
}node;

 node hashTable[MAX];

 int convertToKey(char target[]){
    //stage 1
    int len = strlen(target);
    int temp = 1;

    for(int i = 0; i < len; i++){
        temp *= target[i];
    }

    return temp;
 }

int hashFunction(int key){
    char ch[MAX];

    //stage 2
    sprintf(ch,"%d",key);
    int len = strlen(ch);
    int index = 0;
    int flag = 1;

    for(int i = len-1 ; i >= 0; i--){
        if (flag == 3) break; //stage 3
        index = index * 10 + (ch[i]-'0');
        flag++;
    }

    return index % MAX;
}

 void setTable(){
    for(int i = 0; i < MAX; i++){
        hashTable[i].status = EMPTY;
    }
 }



 void insertData(node data){

    int index = hashFunction(data.key);

    while(hashTable[index].status != EMPTY && hashTable[index].status != DELETED){
        index = (index + 1) % MAX;
    }

    hashTable[index].key = data.key;
    hashTable[index].status = FULL;
    strcpy(hashTable[index].fruit, data.fruit);
    hashTable[index].value = data.value;
 }

 void deleteData(node data){
    int index = hashFunction(data.key);
    int start = index;

    while(hashTable[index].status != EMPTY){
        if (hashTable[index].key == data.key){
            hashTable[index].status = DELETED;
            printf("Sucesfully Deleted\n");
            return;
        }

        if (start == index){
            break;
        }
        index = (index + 1) % MAX;
    }

    printf("Data Not Found\n");
 }



 void search(node data){
    int index = hashFunction(data.key);
    int start = index;

    while(hashTable[index].status != EMPTY){
        if ( hashTable[index].status == FULL && hashTable[index].key == data.key){
            printf("%s-%d\n",hashTable[index].fruit, hashTable[index].value);
            return;
        }

        if (start == index){
            break;
        }

        index = (index + 1) % MAX;
    }

    printf("Data Not Found\n");
 }

 void display(){
    for(int i = 0; i < MAX; i++){
        if (hashTable[i].status == EMPTY || hashTable[i].status == DELETED){
            printf("%d. Data Kosong\n",i);
        }
        else if (hashTable[i].status == FULL){
            printf("%d. %s-%d\n",i, hashTable[i].fruit, hashTable[i].value);
        }
    }
 }

 void menu(){
    setTable();
    int choose = 0, newKey = 0;
    node data;

    while(choose != 5 ){
        printf("======Tropical Delight======\n");
        puts("1. Insert Data");
        puts("2. Delete Data");
        puts("3. Search Data");
        puts("4. View All");
        puts("5. Exit");
        printf(">> ");
        scanf("%d",&choose); gc;

        switch(choose){
            case 1:
                printf("Fruit : ");
                scanf("%s",data.fruit);

                printf("Value : ");
                scanf("%d",&data.value); gc;

                newKey = convertToKey(data.fruit);
                data.key = newKey;
                insertData(data);
                break;
            case 2:
                printf("Insert Key (Fruit): ");
                scanf("%s", data.fruit);
                data.key = convertToKey(data.fruit);

                deleteData(data);
                break;
            case 3:
                printf("Insert key (Fruit) : ");
                scanf("%s",data.fruit);
                data.key = convertToKey(data.fruit);

                search(data);
                break;
            case 4:
                display();
                break;
            case 5:
            printf("Exiting...\n");
                break;
            default:
                printf("Input Invalid\n");
                break;
        }


    }

 }



int main(){
    menu();



    return 0;
}