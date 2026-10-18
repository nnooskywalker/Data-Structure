#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char name[105];
    int nim;
    int height;
    struct node *right;
    struct node *left;
}node;

    node *createNode(char *name, int nim){
        node *newNode = (node*)malloc(sizeof(node));
        strcpy(newNode->name,name);
        newNode->nim = nim;
        newNode->height = 1;
        newNode->right = NULL;
        newNode->left = NULL;

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

    node* rightRotate(node *z){
        node *y = z->left;
        node *temp = y->right;

        y->right = z;
        z->left = temp;

        z->height = 1 + max(height(z->left), height(z->right));
        y->height = 1  + max(height(y->left), height(y->right));

        return y;
    }

    node* leftRotate(node *z){
        node *y = z->right;
        node *temp = y->left;

        y->left = z;
        z->right = temp;

        z->height = 1 + max(height(z->left), height(z->right));
        y->height = 1  + max(height(y->left), height(y->right));

        return y;
    }

    void inOrder(node *root){ 
        if (root == NULL) return;
        inOrder(root->left);
        printf("Nama : %15s | NIM : %d (height: %d)\n", root->name, root->nim, root->height);
        inOrder(root->right);
    }
    
    void preOrder(node *root){
        if (root == NULL) return;
        printf("Nama : %15s | NIM : %d (height: %d)\n", root->name, root->nim, root->height);
        preOrder(root->left);
        preOrder(root->right);
    }
    
    void postOrder(node *root){
        if (root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        printf("Nama : %15s | NIM : %d (height: %d)\n", root->name, root->nim, root->height);
    }

    node *insertNode(node *root,char *name, int nim){
        if (root == NULL){
            return createNode(name, nim);
        }
        if (nim < root->nim){
            root->left = insertNode(root->left, name, nim);
        }
        else if (nim > root->nim){
            root->right = insertNode(root->right, name, nim);
        }
        else{
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if (balance > 1 && nim < root->left->nim){
            return rightRotate(root);
        }
        if (balance < -1 && nim > root->right->nim){
            return leftRotate(root);
        }
        if (balance > 1 && nim > root->left->nim){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && nim < root->right->nim){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // predecessor
    node *largestLeft(node *root){
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }

    // sucessor
    node *lowestRight(node *root){
        while(root->left != NULL){
            root = root->left;
        }

        return root;
    }

    node *deleteNode(node *root, int nim){
        if (root == NULL){
            return root;
        }
        if (nim < root->nim){
            root->left = deleteNode(root->left, nim);
        }
        else if (nim > root->nim){
            root->right = deleteNode(root->right, nim);
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
                strcpy(root->name, temp->name);
                root->nim = temp->nim;
                root->left = deleteNode(root->left, temp->nim);
            }
        }
        if (root == NULL) return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        // ll
        if (balance > 1 && getBalance(root->left) >= 0){
            return rightRotate(root);
        }
        // rr
        if (balance < -1 && getBalance(root->right) <= 0){
            return leftRotate(root);
        }
        // lr
        if (balance > 1 && getBalance(root->left) < 0){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        // rl
        if (balance < -1 && getBalance(root->right) > 0){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void search(node *root, int nim){
        if (root == NULL){
            printf("Person Not Found\n");
            return;
        }
        if (nim < root->nim){
            search(root->left, nim);
        }
        else if (nim > root->nim){
            search(root->right, nim);
        }
        else{
            printf("Person with NIM : %d | Name : %s FOUND!!\n", root->nim, root->name);
        }
    }

int main(){
    node *root = NULL;

    root = insertNode(root, "Aldric", 5);
    root = insertNode(root, "Tan", 4);
    root = insertNode(root, "Octa", 6);
    root = insertNode(root, "Vius", 3);
    root = insertNode(root, "Sandri", 2);
    inOrder(root);

    puts("");
    root = deleteNode(root, 6);
    inOrder(root);
    search(root, 5);







    return 0;
}