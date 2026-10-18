#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100
#define LENGTH 6


void randomCode(char *code){
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    int size = sizeof(charset) - 1;

    for(int i = 0; i < LENGTH; i++){
        int index = rand() % size;
        code[i] = charset[index];
    }

    code[LENGTH] = '\0';
}

typedef struct node{
    int key;
    char plateNum[SIZE];
    char ownerName[SIZE];
    char parkingCode[SIZE];
    struct node *next;
}node;

int convertTokey(char plateNum[]){
    int len = strlen(plateNum);
    int save = 0;

    for(int i = 0; i < len; i++){
        save += plateNum[i];
    }   

    return save;
}


int hashFunction(int key){
    //mid-square
    long long convert = key*key;
    char temp[20];

    sprintf(temp,"%lld", convert);

    int len = strlen(temp);
    int mid = len / 2;
    int index = 0;

    if (len % 2 == 0){
        index = (temp[mid-1] - '0')*10 + (temp[mid] - '0');
    }
    else{
        index = (temp[mid-1] - '0')*100 + (temp[mid] - '0')*10 + (temp[mid+1] - '0');
    }

    //division
    return index % SIZE;
}

node *hashTable[SIZE];

    void setHash(){
        for(int i = 0; i < SIZE; i++){
            hashTable[i] = NULL;
        }
    }

    void insert(int key, char *plateNum, char *ownerName, char *parkingCode){
        int index = hashFunction(key);
        node *newNode = (node*)malloc(sizeof(node));
        strcpy(newNode->plateNum, plateNum);
        strcpy(newNode->ownerName,ownerName);
        strcpy(newNode->parkingCode, parkingCode);
        newNode->key = key;

        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }

    void deleteNode(int key, char *platNomor){
        int index = hashFunction(key);
        node *curr = hashTable[index];
        node *prev = NULL;
    
        while(curr != NULL){
            if (curr->key == key){
                if (prev == NULL){
                    hashTable[index] = curr->next;
                }
                else{
                    prev->next = curr->next;
                }
                free(curr);
                printf("Vehicle %s has exited\n", platNomor);
                return;
            }
            prev = curr;
            curr = curr->next;
        }


        printf("Error : No Parking record found for %s.\n",platNomor);


    }

    void search(char *parkingCode){
        for(int i = 0; i < SIZE; i++){
            node *curr = hashTable[i];


            while(curr != NULL){
                if (strcmp(curr->parkingCode, parkingCode) == 0){
                    printf("Vehicle : %s\n",curr->plateNum);
                    printf("Owner : %s\n",curr->ownerName);
                    return;
                    }
                curr = curr->next;  
            }


            printf("Error : No parking record found for CODE %s\n",parkingCode);


        
        }
    }


    void display(){
        for(int i = 0; i < SIZE; i++){
            node *curr = hashTable[i];

            if (curr == NULL){
                continue;
            }
            else{
                while(curr != NULL){
                    printf("License Plate : %s\n",curr->plateNum);
                    printf("Owner : %s\n",curr->ownerName);
                    printf("Code : %s\n",curr->parkingCode);


                    curr = curr->next;
                }
            }
            printf("\n");
        }
    }

void menu(){
    setHash();
    char platNomor[SIZE], owner[SIZE];
    char inputCode[SIZE], inputPlat[SIZE];
    int choose = 0, key = 0;

    while(choose != 5){
        puts("1. Register Vehicle");
        puts("2. Verify parking");
        puts("3. View All Parked Vehicles");
        puts("4. Remove Vehicle");
        puts("5. Exit");
        printf("Enter your choice: ");
        scanf("%d", &choose);

        switch(choose){
            case 1:
                printf("Enter license plate number : ");
                scanf("%s",platNomor);

                printf("Enter owner name : ");
                scanf(" %[^\n]",owner);

                printf("Parking sucessfull\n");

                char code[LENGTH+1];
                randomCode(code);
                
                printf("Your parking code : %s (keep this for reference)\n",code);

                key = convertTokey(platNomor);
                insert(key, platNomor, owner, code);
                break;
                case 2:
                printf("Enter Parking Code : ");
                scanf("%s",inputCode);
                
                search(inputCode);
                break;
                case 3:
                display();
                break;
            case 4:
                printf("Enter license plate number to remove : ");
                scanf("%s",inputPlat);

                key = convertTokey(inputPlat);

                deleteNode(key, inputPlat);
                break;
                case 5:
                printf("Exiting...");
                break;
                default :
                printf("Invalid");
            }
        }
    }
    
    int main(){
        srand(time(NULL));
        menu();
        
        
        
        
        
        return 0;
}