#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
typedef struct node{
    char ch;
    struct node *left;
    struct node *right;
}node;

node *createNode(char ch){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->ch = ch;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

    node *createTree(char prefix[]){
        struct node *stack[SIZE];
        int top = -1;
        int i = strlen(prefix)-1;

        while(i >= 0){
            char ch = prefix[i];

            if (ch >= '0' && ch <= '9'){
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

    int isOperator(char ch){
        return ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-';
    }

    void inOrder(node *root){
        if (root == NULL) return;
        if (isOperator(root->ch)) putchar('(');
        inOrder(root->left);
        printf("%c",root->ch);
        inOrder(root->right);
        if (isOperator(root->ch)) putchar(')');
    }


    void preOrder(node *root){
        if (root == NULL) return;
        printf("%c",root->ch);
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(node *root){
        if (root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        printf("%c",root->ch);
    }


int main(){
    char preFix[] = "+*54/*6-102+31";

    node *tree = createTree(preFix);

    printf("InOrder : \n");
    inOrder(tree);
    printf("\n");

    printf("PreOrder : \n");
    preOrder(tree);
    printf("\n");

    printf("PostOrder : ");
    postOrder(tree);
    printf("\n");






    return 0;
}