#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int id;
    char name[20];
    int height;
    node *right;
    node *left;
};

node *createNode(int id, char *name){
    node *curr = (node *) malloc(sizeof(node));
    curr->id = id;
    strcpy(curr->name, name);
    curr->height = 1;
    curr->left = NULL;
    curr->right = NULL;

    return curr;
}

int getBalance(node *curr){
    return getHeight(curr->left) - getHeight(curr->right);
}



int getHeight(node *curr){
    if (curr == NULL) return 0;
    
    return curr->height;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

void updateHeight(node *curr){
    curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
}

node *rotateLeft(node *root){
    node *child = root->right;
    node *orphan = child->left;
    
    root->right = orphan;
    child->left = root;
    
    updateHeight(root);
    updateHeight(child);
    
    return child;
}

node *rotateRight(node *root){
    node *child = root->left;
    node *orphan = child->right;
    
    root->left = orphan;
    child->right = root;
    
    updateHeight(root);
    updateHeight(child);
    
    return child;
}

node *reBalance(node *curr){
    int bf = getBalance(curr);
    if (bf > 1){
        if (getBalance(curr->left) < 0){
            curr->left = rotateLeft(curr->left);
        }
        return rotateRight(curr);
    }
    if (bf < -1){
        if (getBalance(curr->right) > 0){
            curr->right = rotateRight(curr->right);
        }
        return rotateLeft(curr);
    }
    return curr;
}

node *insertNode(node *curr, int id, char *name){
    if (curr == NULL){
        return createNode(id, name);
    }
    if (id < curr->id){
        curr->left = insertNode(curr->left, id, name);
    }
    else if (id > curr->id){
        curr->right = insertNode(curr->left, id, name);
    }
    else{
        printf("DUplicate ID\n");
    }
    
    return reBalance(curr);
}

void inOrder(node *root){
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d %s\n",root->id, root->name);
    inOrder(root->right);
}

int main(){
    node *root = NULL;
    
    root = insertNode(root, 45, "Andi");
    root = insertNode(root, 20, "Budi");
    root = insertNode(root, 60, "Citra");
    root = insertNode(root, 10, "Dewa");
    root = insertNode(root, 30, "Eka");
    root = insertNode(root, 50, "Kenshin");
    root = insertNode(root, 70, "Gita");
    root = insertNode(root, 25, "Rita");
    root = insertNode(root, 35, "Andi");
    root = insertNode(root, 5, "Andi");

    inOrder(root);

    return 0;
}






