#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int num;
    struct node*next;
    struct node*prev;
}node;
    node *head = NULL;
    node *tail = NULL;

    node*createNode(int num){
        node *newNode = (node*)malloc(sizeof(node));
        newNode->num = num;
        newNode->next = newNode;
        newNode->prev = newNode;


        return newNode;
    }

int main(){




    return 0;
}