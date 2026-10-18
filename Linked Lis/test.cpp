#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertHead(Node** head, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertTail(Node** head, int value) {
    //1. buat node baru
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    //2. Jika list kosong, newNode menjadi head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    //3. Jika list tidak kosong, cari tail (node terakhir)
    Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;

    //4. Sambung Node terakhir ke newNode
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
  Node *newNode = (Node*) malloc(sizeof(Node));

  newNode->data = 10;
  newNode-> next = NULL;

  insertHead(&newNode,32);
  printList(newNode);

    return 0;
}
