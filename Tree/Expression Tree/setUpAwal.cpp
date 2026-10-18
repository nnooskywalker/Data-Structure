#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    char item;
    struct node *left;
    struct node *right;
}node;

node *create(char item){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;


    return newNode;
}



int main(){




    return 0;
}