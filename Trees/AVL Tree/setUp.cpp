#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    int height;
    struct node *right;
    struct node *left;
}node;

    node *createNode(int data){
        node *newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->height = 1;
        newNode->left = NULL;
        newNode->right = NULL;


        return newNode;
    }

    int height(node *root){
        if (root == NULL){
            return 0;
        }

        return root->height;
    }

    int max(int a, int b){
        return (a > b)? a:b;
    }

    int getBalance(node *root){
        if (root == NULL) return 0;

        return height(root->left) - height(root->right);
    }

    node *rightRotate(node *z){
        node *y = z->left;
        node *temp = y->right;

        y->right = z;
        z->left = temp;

        z->height = 1 + max(height(z->left), height(z->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    node *leftRotate(node *z){
       node *y = z->right;
       node *temp = y->left;

       y->left = z;
       z->right = temp;

       z->height = 1 + max(height(z->left), height(z->right));
       y->height = 1 + max(height(y->left), height(y->right));

       return y;
    }
int main(){





    return 0;
}