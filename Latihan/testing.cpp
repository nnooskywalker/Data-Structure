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

    node *insert(node *root, int data){
        if (root == NULL){
            return createNode(data);
        }
        if (data < root->data){
            root->left = insert(root->left, data);
        }
        else if (data > root->data){
            root->right = insert(root->right, data);
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

    node *largestLeft(node *root){
        while(root->right != NULL){
            root = root->right;
        }

        return root;
    }

    node *remove(node *root, int data){
        if (root == NULL){
            return root;
        }
        if (data < root->data){
            root->left = remove(root->left, data);
        }
        else if (data > root->data){
            root->right = remove(root->right, data);
        }
        else{
            if (root->left == NULL && root->right == NULL){
                free(root);
                return NULL;
            }
            else if (root->left == NULL){
                node *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL){
                node *temp = root->left;
                free(root);
                return temp;
            }
            else{
                node *temp = largestLeft(root->left);
                root->data = temp->data;

                root->left = remove(root->left, temp->data);
            }
        }
        if (root == NULL) return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0){
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0){
            return leftRotate(root);
        }
        if (balance > 1 && getBalance(root->left) < 0){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) > 0){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inOrder(node *root){
        if (root == NULL) return;
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }


int main(){
    node *root = NULL;

    root = insert(root, 20);
    root = insert(root, 35);
    root = insert(root, 10);
    root = insert(root, 55);

    inOrder(root);

    remove(root, 35);
    printf("\n");
    inOrder(root);
    remove(root, 20);
    printf("\n");
    inOrder(root);



    return 0;
}