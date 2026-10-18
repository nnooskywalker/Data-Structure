#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char data;
    struct node *right;
    struct node *left;
}node;


node *createNode(char data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int operator(char data){

    switch (data){
    case '+' : return 1;
    case '-' : return 1;
    case '*' : return 1;
    case '/' : return 1;
    case '^' : return 1;
    default : return 0;

    }
}

node *tree(char postfix[]){
    struct node *stack [100];
    int top = -1;
    int i = 0;

    while(postfix[i] != '\0'){
        char ch = postfix[i];

        if (ch >= 'A' && ch <= 'Z'){
            node *newNode = create(ch);
            stack[++top] = newNode;
        }
        else{
            node *newNode = create(ch);
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
        i++;
    }
    return stack[top];
}


void inOrder(node *root){
    if (root == NULL) return;

    if(operator(root->data)) putchar('(');
    inOrder(root->left);
    printf("%c",root->data);
    inOrder(root->right);
    if(operator(root->data)) putchar(')');

}

void postOrder(node *root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%c",root->data);
}

void preOrder(node *root){
    if(root == NULL) return;

    printf("%c",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
int main (){



    return 0;
}