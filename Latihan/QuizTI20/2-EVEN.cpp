#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char value;
    struct node *right;
    struct node *left;
}node;

node *createNode(char ch){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->value = ch;
    newNode->left = NULL;
    newNode->right = NULL;


    return newNode;
}

node *createTree(char preFix[]){
    struct node *stack[100];
    int top = -1;
    int i = strlen(preFix);

    while(i >= 0){
        char ch = preFix[i];

        if(ch >= '0' && ch <= '9'){
            node *newNode = createNode(ch);
            stack[++top] = newNode;
        }
        else{
            node *newNode = createNode(ch);
            newNode->left = stack[top--];
            newNode->right = stack[top--];
            stack[++top] = newNode;
        }
        i--;
    }

    return stack[top];
}

void inOrder(node *root){
    if (root == NULL) return;
    inOrder(root->left);
    printf("%c",root->value);
    inOrder(root->right);
}

void preOrder(node *root){
    if(root == NULL) return;
    printf("%c",root->value);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root){
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c",root->value);
}



int main(){
    char prefix[] = "/+*102-*834+62";

    node *tree = createTree(prefix);

    printf("Inorder : ");
    inOrder(tree);
    printf("\n");


    printf("Preorder : ");
    preOrder(tree);
    printf("\n");

    printf("Postorder : ");
    postOrder(tree);
    printf("\n");

    return 0;
}