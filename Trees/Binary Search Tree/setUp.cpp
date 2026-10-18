#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char data;
    struct node *left;
    struct node *right;
}node;

node *create(char data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
int main(){

}