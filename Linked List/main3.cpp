#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char name[100];
    int id;
    struct node *next;
    struct node *prev;
}node;

    node *head = NULL;
    node *tail = NULL;

    node*createNode(char *name, int id){
        node *newNode = (node*)malloc(sizeof(node));
        strcpy(newNode->name,name);
        newNode->id = id;
        newNode->next = NULL;
        newNode->prev = NULL;


        return newNode;
    }

    void addHead(char *name, int id){
        node *newNode = createNode(name, id);

        if (head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addTail(char *name, int id){
        node *newNode = createNode(name, id);

        if (head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    

    void addMid(int pos, char *name, int id){
        node *newNode = createNode(name, id);

        if (head == NULL){
            printf("Empty List\n");
            return;
        }

        if (pos < 1){
            printf("Invalid position\n");
            return;
        }
        
        if(pos == 1){
            addHead(name, id);
            return;
        }
        
        node *curr = head;
        int count = 1;

        while(count < pos - 1 && curr != NULL){
            curr = curr->next;
            count++;
        }

        if(curr->next == NULL){
            curr->next = newNode;
            newNode->prev = curr;
            return;
        }

        newNode->next = curr->next;
        curr->next->prev = newNode;
        curr->next = newNode;
        newNode->prev = curr;
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
            head->prev = NULL;

            free(temp);


        }
    }

    void deleteTail(){
        if (tail == NULL){
            printf("List Kosong\n");
            return;
        }

        if(head == tail){
            free(head);
            head = tail = NULL;
        }
        else{
            node*del = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(del);
        }
    }

    void deleteMid(char *name, int id){
        if (head == NULL){
            printf("List Kosong\n");
            return;
        }

        if(strcmp(head->name,name) == 0){
            deleteHead();
            return;
        }

        if(strcmp(tail->name,name) == 0){
            deleteTail();
            return;
        }

        node *temp = head;

        while(temp != NULL && temp->id != id){
            temp = temp->next;
        }

        if(temp == NULL){
            printf("Not Found\n");
            return;
        }

        node *sNext = temp->next;
        node *sPrev = temp->prev;

        sPrev->next = sNext;
        sNext->prev = sPrev;
        free(temp);
    }

    

    void show(){
        node *curr = head;

        while(curr != NULL){
            printf("%s %d -> ",curr->name,curr->id);
            curr = curr->next;
        }
        
    }
    
    void showReverse(){
        node *curr = tail;
        
        while(curr != NULL){
            printf("%s %d -> ",curr->name,curr->id);
            curr = curr->prev;
        }
    }


int main(){
    addTail("Nino",2334);
    addTail("Gilang",9383);
    addTail("Findo",29820);
    addTail("Ruben",92873);
    addTail("Faiz",9383);
    addTail("Jasmine",123345);
    //addMid(3,"Jojo",9832);
    deleteMid("Jasmine",8283);
    deleteMid("Nino",8283);


    puts("Show Forward : ");
    show();
    printf("\n");






return 0;
}