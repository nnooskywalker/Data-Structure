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
        if (root == NULL) return 0;

        return root->height;
    }

    int max(int a, int b){
        return (a > b) ? a : b;
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

    node *insertNode(node *root, int data){
        if (root == NULL){
            return createNode(data);
        }
        if (data < root->data){
            root->left = insertNode(root->left, data);
        }
        else if (data > root->data){
            root->right = insertNode(root->right, data);
        }
        else{
            return root;
        }
        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if (balance > 1 && data < root->left->data){
            return rightRotate(root);
        }
        if (balance < -1 && data > root->right->data){
            return  leftRotate(root);
        }
        if (balance > 1 && data > root->left->data){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && data < root->right->data){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    node *largestLeft(node *root){
        while(root->right != NULL){
            root = root->right;
        }

        return root;
    }

    node *deleteNode(node *root, int data){
        if (root == NULL){
            printf("Data Not Found\n");
            return;
        }
        if (data < root->data){
            root->left = deleteNode(root->left, data);
        }
        else if (data > root->data){
            root->right = deleteNode(root->right, data);
        }
        else{
            if (root->left == NULL && root->right == NULL){
                free(root);
                return root;
            }
            else if (root->right == NULL){
                node *temp = root->left;
                free(root);
                return temp;
            }
            else if (root->left == NULL){
                node *temp = root->right;
                free(root);
                return temp;
            }
            else{
                node *temp = largestLeft(root->left);
                root->data = temp->data;
                root->left = deleteNode(root->left, temp->data);
            }
            if (root == NULL) return root;

            root->height = 1 + max(height(root->left), height(root->right));
            int balance = getBalance(root);

            if (balance > 1 && data < root->left->data){
                return rightRotate(root);
            }
            if (balance < -1 && data > root->right->data){
                return leftRotate(root);
            }
            if (balance > 1 && data > root->left->data){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (balance < -1 && data < root->right->data){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root;
        }
    }
int main(){




    return 0;
}