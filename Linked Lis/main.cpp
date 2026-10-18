#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int num;
    struct node *next;
}node;

    node *head = NULL;
    node *tail = NULL;

node *createNode (int num){
    node *newNode =(node*)malloc(sizeof(node));

    newNode->num = NULL;
    newNode->next = newNode;


    return newNode;
}

void addHead(int num){
    node *newNode = createNode(num);
    if (head == NULL){
        head = newNode;
    }
    else{
        tail->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void addTail(int num){
    node *newNode = createNode(num);

    if(tail == NULL){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}


void addMid(int num, int pos){
    node *newNode = createNode(num);

    if(head->num == num){
        addHead(num);
        return;
    }

    node *c = head;
    int count = 1;
  


    do{
        c = c->next;
        count++;
    }while(c != head && count < pos - 1);

    if(c == head) printf("Not Found");

    newNode->next = c->next;
    c->next = newNode;

    if(c == tail){
        tail = c;
    }
}

void delHead(){
    if (head == NULL){
        printf("List is empty\n");
        return;
    }

    if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        node *temp = head;
        head = head->next;
        tail->next = head;
        free(temp);

    }
}

void delTail(){
    if(tail == NULL){
        printf("List is empty\n");
        return;
    }

    if(head == tail){
        free(tail);
        head = tail = NULL;
    }
    else{
        node *curr = head;
        
        while(curr->next != tail){
            curr = curr->next;
        }

      curr->next = head;
      free(tail);
      tail = curr;



    }
}


void delMid(int num){

    if (head == NULL){
        printf("List Kosong");
        return;
    }

    if(head->num == num){
        delHead();
        return;
    }

    if(tail->num == num){
        delTail();
        return;
    }


    node *curr = head;

  do{
    curr = curr->next;
  }while(curr != head && curr->next->num != num);

    if (curr == head){
        printf("Not Found\n");
    }

    node *target = curr->next;
    curr->next = target->next;

    free(target);
}



int main(){





    return 0;
}