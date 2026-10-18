#include <stdio.h>
typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
} node;

    node *head = NULL;
    node *tail = NULL;

node* createNode(int num){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = num;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}


int main (){




}