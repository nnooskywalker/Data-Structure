#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

    node *head = NULL;
    node *tail = NULL;

    node *createNode (int data){
        node *newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->next = NULL;

        return newNode;
    }

    void insertData(int data){
        node *newNode = createNode(data);

        if (head == NULL || data < head->data ){
            newNode->next = head;
            head = newNode;
        }
        else{
            node *curr = head;

            while(curr->next != NULL && curr->next->data <= data){
                curr = curr->next;
            }

            if (curr == NULL){
                printf("Data Not Found\n");
                return;
            }

            newNode->next = curr->next;
            curr->next = newNode;
        }
    }


    void display(){
        node *curr = head;

        while (curr != NULL){
            printf("%d ->", curr->data);
            curr = curr->next;
        }
    }

int main(){
    insertData(1);
    insertData(2);
    insertData(1);
    display();



    return 0;
}