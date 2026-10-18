#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define gc getchar()
typedef struct node{
    char name[10];
    char typeTicket[10];
    int precedence;
    struct node *next;
    struct node*prev;
}node;

    node *head = NULL;
    node *tail = NULL;

    node *createNode(char *name, char *ticket, int precedence){
        node *newNode = (node*)malloc(sizeof(node));
        strcpy(newNode->name,name);
        strcpy(newNode->typeTicket, ticket);
        newNode->precedence = precedence;
        newNode->next = NULL;
        newNode->prev = NULL;

        return newNode;
    }



    void insertNode(char *name, char *ticket){
        int precedence = 0;

        if (strcmp(ticket,"FAST_TRACK") == 0){
            precedence = 1;
        }
        else if (strcmp(ticket,"REGULER") == 0){
            precedence = 2;
        }

        node *newNode = createNode(name, ticket, precedence);

        if (head == NULL){
            head = tail = newNode;
        }
        else if(precedence < head->precedence){
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (precedence > head->precedence){
            node *curr = head;

            while(curr->next != NULL && curr->next->precedence <= precedence){
                curr = curr->next;
            }

            if(curr->next == NULL){
                curr->next = newNode;
                newNode->prev = curr;
                newNode->next = NULL;
                tail = newNode;
                return;
            }


            newNode->next = curr->next;
            curr->next->prev = newNode;
            curr->next = newNode;
            newNode->prev = curr;
        }
        else if (precedence == head->precedence){
            node *curr = head;

            while(curr->next != NULL && curr->next->precedence == precedence){
                curr = curr->next;
            }

            if (curr->next == NULL){
                curr->next = newNode;
                newNode->prev = curr;
                newNode->next = NULL;
                tail = newNode;
                return;
            }

            newNode->next = curr->next;
            curr->next->prev = newNode;
            curr->next = newNode;
            newNode->prev = curr;
        }
    }

    void display(){
        node *curr = head;

        while(curr != NULL){
            printf("Name : %s\n",curr->name);
            printf("Ticket : %s\n\n",curr->typeTicket);
            curr = curr->next;
        }
    }

    void popHead(){
        if (head == NULL){
            printf("List Kosong\n");
            return;
        }

        if(head == tail){
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

    void popTail(){
        if (tail == NULL){
            printf("List Kosong\n");
            return;
        }

        if(head == tail){
            free(tail);
            head = tail = NULL;
        }
        else{
            node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
    }



    void remove(char *name){
        if (head == NULL){
            printf("List Kosong\n");
            return;
        }
        if(strcmp(head->name,name) == 0){
            popHead();
            return;
        }
        if(strcmp(tail->name,name) == 0){
            popTail();
            return;
        }

        node *curr = head;

        while(curr != NULL && strcmp(curr->name,name) != 0){
            curr = curr->next;
        }

        if(curr == NULL){
            printf("Data Not Found\n");
            return;
        }

        node *sNext = curr->next;
        node *sPrev = curr->prev;

        sPrev->next = sNext;
        sNext->prev = sPrev;
        free(curr);

    }

    void call(){
        node *curr = head;

        while(curr != NULL){
            curr = curr->next;
        }
    }


int main(){
    insertNode("ANI","FAST_TRACK");
    insertNode("BANI","REGULER");
    insertNode("CANI","FAST_TRACK");
    insertNode("DANI","REGULER");
    insertNode("ENI","FAST_TRACK");
    insertNode("FANI","REGULER");
    insertNode("GANI","REGULER");

    display();


    return 0;

}