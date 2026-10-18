#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define gc getchar()

typedef struct node{
    char nama[100];
    int level;
    char arrTime[100];
    struct node *next;

}node;

    node *head = NULL;
    node *tail = NULL;

    node* createNode(char *nama, int level, char *time){
        node *newNode = (node*)malloc(sizeof(node));

        strcpy(newNode->nama,nama);
        newNode->level = level;
        strcpy(newNode->arrTime, time);

        newNode->next = NULL;
        return newNode;
        
    }

    void deleteHead(){
        if (head == NULL){
            printf("Empty List\n");
            return;
        }

        if (head == tail){
            free(head);
            head = tail = NULL;
        }
        else{
            node *temp = head;
            head = head->next;
            free(temp);
        }

    }

    void insertPrio(char *nama, int level, char *time){
        node *newNode = createNode(nama, level, time);

        if (head == NULL || level < head->level){
            newNode->next = head;
            head = newNode;
        }
        else{
            node *curr = head;

            while(curr->next != NULL && level >= curr->next->level){
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
        
    }

    void show(){
        node *c = head;
        int k = 1;

        while(c != NULL){
            printf("%d. Name : %s, priority : %d\n", k, c->nama, c->level);
            c = c->next;
            k++;
        }
    }


    void searching(char *name){
        node *c = head;

        if (c == NULL){
            printf("List Kosong\n");
            return;
        }


        while(c != NULL){
            if(strcmp(c->nama,name) == 0){

            }
            c = c->next;
        }
    }



    void menu(){
        int choose = 0, intPrio = 0, flag = 0;
        char inputName[100], inputPrio[100], arrTime[100], searchName[100];
        
        while(choose != 5){
            puts("========Hospital Emergency Room Queue======");
            puts("1. Register Patient");
            puts("2. Call Next Patient");
            puts("3. Update Condition");
            puts("4. View Queue");
            puts("5. Exit");
            printf(">> ");
            scanf("%d",&choose); gc;
            system("cls");
            switch(choose){
                case 1:
                    printf("Nama : ");
                    scanf(" %[^\n]",inputName); 
                    printf("Priority Level (Emergency, Urgent, Normal) : ");
                    scanf("%s",inputPrio); gc;
                    printf("Arrival Time : ");
                    scanf("%s",arrTime); gc;
    
                    if(strcmp(inputPrio,"Emergency") == 0){
                        intPrio = 1;
                    }
                    else if(strcmp(inputPrio,"Urgent") == 0){
                        intPrio = 2;
                    }
                    else if(strcmp(inputPrio,"Normal") == 0){
                        intPrio = 3;
                    }
                    else{
                        printf("Invalid\n");
                    }
    
                    insertPrio(inputName, intPrio, arrTime);
                    flag++;
                    gc;
                    system("cls");
                    break;
                case 2:
                    if (flag == 0){
                        printf("List Kosong\n");
                        return;
                    }
                    else{
                        printf("Name : %s\n",head->nama);
                    }

                    deleteHead();
                    break;
                case 3:
                    printf("Search Name : ");
                    scanf(" %[^\n]",searchName); 
    
                    break;
                case 4:
                        show();

                    gc;
                    system("cls");
                    break;
                case 5:
                printf("Exiting....");
                    break;
            }
    
        }
    }
    

int main (){
    menu();



    return 0;
}