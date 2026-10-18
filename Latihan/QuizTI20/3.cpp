#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char nama[100];
    int emergencyStatus;
    int fuelLevel;
    struct node *next;
}node;

    node *head = NULL;
    node *tail = NULL;

node *createNode(char *nama, int fuel, int emergency){
    node *newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->nama,nama);
    newNode->emergencyStatus = emergency;
    newNode->fuelLevel = fuel;
    newNode->next = NULL;

    return newNode;
}

void enqueue(char *nama, int fuel, int emergency){
    node *newNode = createNode(nama, fuel, emergency);

    if (head == NULL || emergency > head->emergencyStatus){
        newNode->next = head;
        head = newNode;
    }
    else if (emergency < head->emergencyStatus){
        node *curr = head;

        while(curr->next != NULL && curr->next->emergencyStatus > emergency){
                curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }
    else if (emergency == head->emergencyStatus){
        if(fuel < head->fuelLevel){
            newNode->next = head;
            head = newNode;
        }
        else{
            node *curr = head;

            while(curr->next != NULL && curr->next->fuelLevel <= fuel){
                curr = curr->next;
            }

            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
}
void dequeue(){
    if (head == NULL){
        printf("Data Kosong\n");
        return;
    }

    if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        node *curr = head;
        head = head->next;
        free(curr);
    }
}

void display(){
    node *curr = head;

    while(curr != NULL){
        printf("%s -> ", curr->nama);
        curr = curr->next;
    }
    printf("NULL\n");

}

int main(){
    enqueue("Apollo",75,0);
    enqueue("Voyager",50,0);
    enqueue("Odyssey",90,1);
    enqueue("Endeavour",15,0);
    enqueue("Pioneer",80,1);


   puts("Docking Order : ");
   display();


   dequeue();

   puts("Docking Order After Dequeue : ");
   display();

    






    return 0;
}
