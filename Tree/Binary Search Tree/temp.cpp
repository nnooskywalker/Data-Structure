#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char data;
    node *left;
    node *right;
}node;

node *createNode(char data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node *insertBST(node *root, char data){
    if (root == NULL){
        return createNode(data);
    }

    // anak kiri
    if(data < root->data){
        root->left = insertBST(root->left, data);
    }
    //anak kanan
    else if(data > root->data){
        root->right = insertBST(root->right, data);
    }


    return root;
}

// pre (sebelum)

void prefix(node *root){
    if (root == NULL) return;

    printf("%c",root->data);
    prefix(root->left);
    prefix(root->right);
}

void postFix(node *root){
    if (root == NULL) return ;
    postFix(root->left);
    postFix(root->right);
    printf("%c",root->data);
}

int isOperator(char data){
    return data == '+' || data == '-' ||
            data == '*' || data == '/' ||
            data == '^';

    // return 1 kalau karakter nya salah satu dari ini
}


void infix(node *root){
    if (root == NULL){
        return;
    }

    if (isOperator(root->data)) putchar('(');
    infix(root->left);
    printf("%c",root->data);
    infix(root->right);
    if (isOperator(root->data)) putchar(')');
}

// construct suatu tree
// dari expression postfix (postfix --> tree)
node *postTree(char postfix[]){
    struct node *stack [100];
    int top = -1;
    int i = 0;

    while(postfix[i] != '\0'){
        char ch = postfix[i];

        if (ch >= 'A' && ch <= 'Z' || ch >= 1 && ch <= 9){
            node *newNode = createNode(ch);
            stack[++top] = newNode;
        }
        else{
            if (top < 1) return NULL;
            node *newNode = createNode(ch);
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
        i++;
    }
    if(top != 0) return NULL;   //expression nya tidak valid
    return stack[top];  //root
}

node *preTree(char prefix[]){
    struct node *stack[100];
    int top = -1;
    int i = strlen(prefix) - 1;

    while(i >= 0){
        char ch = prefix[i];

        if(ch >= 'A' && ch <= 'Z'){
            node *newNode = createNode(ch);
            stack[++top] = newNode;
        }
        else{
            if (top < 1) return NULL;
            node *newNode = createNode(ch);
            newNode->left = stack[top--];
            newNode->right = stack[top--];

            stack[++top] = newNode;
        }
        i--;
    }
    if (top != 0) return NULL;
    return stack[top];
}


int main(){
    node *root = NULL;

    root = insertBST(root, 'C');
    root = insertBST(root, 'A');
    root = insertBST(root, 'E');
    infix(root);


    


    return 0;
}