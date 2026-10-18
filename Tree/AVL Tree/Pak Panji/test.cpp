#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    int height;
    struct node *left;
    struct node *right;
}node;

node *createNode(int data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

int height(node *root){
    if (root == NULL){
        return 0;
    }
    return root->height;
}

// update height node
int max(int a, int b){
    return (a > b) ? a : b;
}

int getBalance(node *root){
    if (root == NULL){
        return 0;
    }

    return height(root->left) - height(root->right);
}

node *rightRotate(node *z){
    node *y = z->left;
    node *T3 = y->right;

    //Perform rotation
    y->right = z;
    z->left = T3;

    //Update heights
    z->height = max(height(z->left), height(z->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    
    return y;
}

node *leftRotate(node *z){
    node *y = z->right;
    node *T3 = y->left;

    y->left = z;
    z->right = T3;
    
    z->height = max(height(z->left), height(z->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

node *insertNode (node *root, int data){
    if (root == NULL){
        return createNode(data);
    }
    if (data < root->data){
        root->left = insertNode(root->left, data);
    }
    else if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    else return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    //LL case
    if (balance > 1 && data < root->left->data){
        return rightRotate(root); 
    }

    //RR Case
    if (balance < -1 && data > root->right->data){
        return leftRotate(root);
    }

    //LR Case
    if (balance > 1 && data > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //RL Case
    if (balance < - 1 && data < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main(){




    return 0;
}