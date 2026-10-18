#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int num;
    struct node *next;
}node;
    node *head = NULL;
    node *tail = NULL;

    node *createNode(int num){
        node *newNode = (node*)malloc(sizeof(node));
        newNode->num = num;
        newNode->next = newNode;

        return newNode;
    }


int main (){



    return 0;
}