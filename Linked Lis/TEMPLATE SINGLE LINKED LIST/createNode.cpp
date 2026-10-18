#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
        char name[100];
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

int main (){




    return 0;
}