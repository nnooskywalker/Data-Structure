#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define gc getchar()

typedef struct node{
    char name[1000];
    struct node *next;
} node;

    node *head = NULL;
    node *tail = NULL;

    node* createNode(char *name){
        node *newNode = (node*)malloc(sizeof(node));
        strcpy(newNode->name,name);

        newNode->next = NULL;

        return newNode;
    }

    void insertTail(char *name){
        node *newNode = createNode(name);

        if (head== NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void popTail(){
        node *c = head;

        if (tail == NULL){
            printf("List Kosong");
            return;
        }

        if (head == tail){
            free(head);
            head = tail = NULL;
            return;
        }

        while(c->next != tail){
            c = c->next;
        }

        free(tail);
        tail = c;
        tail->next = NULL;
        printf("Delete Successfully\n");
    }

    void popALL(){
     node *c = head;


    if (c == NULL){
        printf("Empty");
        return;
    }
    else{
        while(c != NULL){
            node *temp = c;
            c = c->next;
            free(temp);
   
        }
        head = NULL;
        printf("Delete Succesfully\n");
    }
    

 
    }

    void viewList(){
        node *c = head;
        int k = 1;

        if (c == NULL){
            printf("Empty\n");
            return;
        }
        while(c != NULL){
            printf("%d. %s\n",k,c->name);
            c = c->next;
            k++;
        }
    }

void menu(){
    int choose = 0;
    char word[1000];

    while(choose != 5){
        puts("1. Add Word");
        puts("2. Undo");
        puts("3. View Document");
        puts("4. Clear All");
        puts("5. Exit");
        printf(">> ");
        scanf("%d",&choose);
        gc;
        system("cls");
        switch(choose){
            case 1:
                printf("Insert a word : ");
                scanf("%[^\n]",word); gc;
                insertTail(word);
                gc;
                system("cls");
                break;
            case 2:
                popTail();
                gc;
                system("cls");
                break;
            case 3:
                viewList();
                gc;
                system("cls");
                break;
            case 4:
                popALL();
                gc;
                system("cls");
                break;
            case 5:
                printf("Exiting....");
                break;
            default:
                printf("Input salah!");
                gc;
                system("cls");
        }
    }

    
}

int main (){

    menu();




    return 0;
}