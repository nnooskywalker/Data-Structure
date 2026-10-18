#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define gc getchar()
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

    node *deleteNode(node *root, int data){
        if (root == NULL){
            printf("Data Not Found\n");
            return root;
        }
        else if (data < root->data){
            root->left = deleteNode(root->left, data);
        }
        else if (data > root->data){
            root->right = deleteNode(root->right, data);
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
                root->left = deleteNode(root->left, temp->data);
            }
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

    void search(node *root, int data){
        if (root == NULL){
            printf("%d -> NOT FOUND\n", data);
            return;
        }
        if (data < root->data){
            search(root->left, data);
        }
        else if (data > root->data){
            search(root->right, data);
        }
        else{
            printf("%d -> FOUND\n", data);
        }
    }

    void inOrder(node *root){
        if (root == NULL) return;
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }

    void leafNode(node *root){
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL){
            printf("%d ", root->data);
            return;
        }

        leafNode(root->left);
        leafNode(root->right);
    }


int main(){
    node *root = NULL;
    int input = 0;

    scanf("%d",&input); gc;

    for(int i = 0; i < input; i++){
        int data = 0;
        scanf("%d",&data); gc;
        root = insertNode(root, data);
    }

    int input2 = 0;

    scanf("%d",&input2); gc;

    for (int i = 0; i < input2; i++){
        char menu[100];
        int data = 0;

        scanf(" %s", menu);

        if (strcmp(menu,"REPORT") == 0){
            int getHeight = height(root);
            printf("%d\n", getHeight);
            leafNode(root);
        }
        else{
            scanf("%d",&data); gc;

            if (strcmp(menu,"SRC") == 0){
                search(root, data);
            }
            else if (strcmp(menu,"DEL") == 0){
                root = deleteNode(root, data);
                inOrder(root);
                printf("\n");
            }
        }




    }



    return 0;
}